#include <iostream>
#include<cmath>

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
    void changevolume(int a)
    {
        volume = a;
    }
    void changevalue(int b)
    {
        value = b;
    }
    ~thing(){}
};

int main()
{
    int volume;
    int n;
    cout << "Please input the volume of the bag: "<<endl;
    cin>>volume;
    cout << "Please input the num of things"<<endl;
    cin>>n;
    thing *a = new thing[n];
    for(int i=0;i<n;i++)
    {
        int tempa,tempb;
        cout<<"The "<<i+1<<" thing's volume is : "<<endl;
        cin>>tempa;
        a[i].changevolume(tempa);
        cout<<"The "<<i+1<<" thing's value is : "<<endl;
        cin>>tempb;
        a[i].changevalue(tempb);
    }
    int tempvolume=0;
    int tempvalue=0;
    int maxvalue=0;
    for(int i=0;i<pow(2,n);i++)
    {

        for(int j=0;j<n;j++)
        {
            if(i%2==1)
            {
                tempvolume+=a[j].getvolume();
                tempvalue+=a[j].getvalue();
            }
            i=i/2;
        }
        if(tempvolume<=volume)
        {
            cout<<"hello1"<<endl;
            if(tempvalue>maxvalue)
                maxvalue=tempvalue;
        }
    }
    delete a;
    cout<<"The MAXvalue is : "<<maxvalue<<endl;
    return 0;
}
