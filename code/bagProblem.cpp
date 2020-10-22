#include <iostream>
using namespace std;

class thing{
private:
    int volume;
    int value;
public:
    thing()
    {
        volume=0;
        value=0;
    }
    thing(int a,int b)
    {
        volume = a;
        value = b;
    }
    int getvolume()
    {
        return volume;
    }
    int getvalue()
    {
        return value;
    }
    void changeweigh(int a)
    {
        volume = a;
    }
    void changevalue(int b)
    {
        value = b;
    }
};

int main()
{
    int n,volume;
    cout << "Please input the volume of the bag: "<<endl;
    cin>>volume;
    cout << "Please input the num of things"<<endl;
    const int  n =10;
    int tempvolume,tempvalue,maxvalue;
    for(int i=0;i<(n<<1);i++)
    {

        for(int j=0;j<n;j++)
        {
            if(i%2==1)
            {
                tempvolume+=a[j].getvolume;
                tempvalue+=a[j].getvalue;
            }
            i=i/2;
        }
        if(tempvolume<=volume)
        {
            if(tempvalue>maxvalue)
                maxvalue=tempvalue;
        }
    }
//    int nowvalue=0;
//    int value=0;
//    for(int i=1;i<=n;i++)
//    {
//        value=value+i;
//
//    }
//    int maxvolume,maxvalue;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            if(j<=i)continue;
//            maxvolume=a[i].volume+a[j].volume;
//            if(maxvolume<=volume)
//                maxvalue=a[i].value+a[j].value;
//            else
//                maxvalue=a[i].value;
//            for(int k=1;k<=n;k++)
//            {
//                if(k<=j)continue;
//                if(maxvolume+a[k].volume<=volume)
//                {
//                    maxvalue = maxvalue+a[k].value;
//                    maxvolume = maxvolume+a[k].volume;
//                }
//            }
//        }
//    }
    return 0;
}
