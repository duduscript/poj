#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main()
{
    map<string,int> Haab;
    map<int,string> Tzolkin;
    int n;
    Haab["pop"]=0,Haab["no"]=1,Haab["zip"]=2,Haab["zotz"]=3,Haab["tzec"]=4,Haab["xul"]=5,
    Haab["yoxkin"]=6,Haab["mol"]=7,Haab["chen"]=8,Haab["yax"]=9,Haab["zac"]=10,
    Haab["ceh"]=11,Haab["mac"]=12,Haab["kankin"]=13,Haab["muan"]=14,Haab["pax"]=15,
    Haab["koyab"]=16,Haab["cumh"]=17,Haab["uayet"]=18;
    Tzolkin[0]="imix",Tzolkin[1]="ik",Tzolkin[2]="akbal",Tzolkin[3]="kan",Tzolkin[4]="chicchan",
    Tzolkin[5]="cimi",Tzolkin[6]="manik",Tzolkin[7]="lamat",Tzolkin[8]="muluk",Tzolkin[9]="ok",
    Tzolkin[10]="chuen",Tzolkin[11]="eb",Tzolkin[12]="ben",Tzolkin[13]="ix",Tzolkin[14]="mem",
    Tzolkin[15]="cib",Tzolkin[16]="caban",Tzolkin[17]="eznab",Tzolkin[18]="canac",Tzolkin[19]="ahau";
    cin>>n;
    cout<<n<<endl;
    while(n--){
        int day_h,year_h,day_t,year_t,month_t,sum;
        char dot;
        string h;
        cin>>day_h>>dot>>h>>year_h;
        map<string,int>::iterator iter=Haab.find(h);
        sum=day_h+(*iter).second*20+year_h*365+1;
        year_t=sum/260;
        if(sum%260==0)
            --year_t;
        day_t=sum%13;
        if(day_t==0)  day_t=13;
        month_t=(sum-1)%20;
        cout<<day_t<<" "<<Tzolkin[month_t]<<" "<<year_t<<endl;
    }
    return 0;
}