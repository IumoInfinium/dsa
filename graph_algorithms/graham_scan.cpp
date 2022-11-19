#include <bits/stdc++.h>
using namespace std;

// Utility/ function for finding the movement of 3rd point.
// 0 ... points are collinear
// 1 ... point is helping in forming non-convex hull
// -1 ... point is helping in forming convex hull
int orientation(vector<int>& a, vector<int>& b, vector<int>& c){
    // cross product of vectors
    double vect = a[0]*(b[1]-c[1]) + b[0]*(c[1]-a[1]) + c[0]*(a[1]-b[1]);
    if(vect <0) return -1;
    if(vect >0) return 1;
    return 0;
}

bool cw(vector<int>& a,vector<int>& b,vector<int>& c,bool include_collinear){
    int angle = orientation(a,b,c);
    return angle <0 || (include_collinear && angle ==0);
}


// Checks it the 3 points are collinear or not
bool collinear(vector<int>& a,vector<int>& b,vector<int>& c){
    return orientation(a,b,c)==0;
}

// Graham scan working function
vector<vector<int>> graham_scan(vector<vector<int>>& points, bool include_collinear=false){
    // Finding min element in points, with lowest y-index.
    vector<int> P0 = *min_element(
        points.begin(), points.end(),[](vector<int>& a, vector<int>& b){
            return (a[1],a[0]) < (b[1],b[0]);
        }
    );

    // Sorting remaining n-1 points and arranging them on the basis of their polar angle.
    sort(points.begin(), points.end(), [&P0](vector<int>& a, vector<int>& b){
        int angle  = orientation(P0,a,b);
        if(angle == 0)
            return (P0[0]-a[0])*(P0[0]-a[0]) + (P0[1]-a[1])*(P0[1]-a[1])
                <  (P0[0]-b[0])*(P0[0]-b[0]) + (P0[1]-b[1])*(P0[1]-b[1]);
        return angle <0;
    });

    // if collinears need to be included, make them visible to the counter-clockwise movement through points.
    if(include_collinear){
        int i = (int)points.size()-1;
        while( i>= 0 &&  collinear(P0,points[i], points.back())) i--;

        reverse(points.begin()+i+1,points.end());
    }

    // vector acting as a stack for backtracking
    vector<vector<int>> st;

    // iterating through every point and popping out the points making wrong angle/ orientation
    // And pushing, new point back to stack 
    for(int i=0; i< (int) points.size(); i++){
        while( st.size() > 1 &&  !cw(st[st.size()-2], st.back(), points[i],include_collinear))
            st.pop_back();
        st.push_back(points[i]);
    }
    return st;
}

int main(){
    vector<vector<int>> points = {{1,1},{2,0},{2,2},{2,4},{3,3},{4,2}};
    vector<vector<int>> nodes= graham_scan(points, true);

    for(auto node: nodes){
        printf("%d : %d\n",node[0],node[1]);
    } 
    return 0;
}