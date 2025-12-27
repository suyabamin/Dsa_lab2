<<<<<<< HEAD
/*
=======
>>>>>>> 4b2d0db (added mid)
#include<bits/stdc++.h>
using namespace std;


struct activity
{
    int s;
    int f;
    int indx;
};
bool compareActivity(const activity &a,const activity &b){
    return a.f<b.f;
}

void printMaxActivites(vector<activity>&acts){
<<<<<<< HEAD
    if(acts.empty()){
        return;
    }
    sort(acts.begin(),acts.end(),compareActivity);
=======
    if(acrs.empty()){
        return;
    }
    sort(acrs.begin(),acrs.end(),compareActivity);
>>>>>>> 4b2d0db (added mid)
    cout<<"following activities are selected(original_index:(start,finish))\n";
    int last_finish=acts[0].f;
    cout<<

}

int main(){
    int n,s,f;
    cin>>n;
    vector<activity>acts;
    for(int i=0;i<n;i++){
        cout<<"ener the start and finish time of activity"<<i<<endl;
        cin>>s>>f;
        acts.push_back(activity{s,f,i});
    }
    printMaxActivites(acts);
<<<<<<< HEAD
}*/
=======
}
>>>>>>> 4b2d0db (added mid)
