#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX_REQ_NUM = 30;

//区间：开始时间，结束时间，权值
struct Interval {
  int beginTime;
  int endTime;
  int weight;
};

//重载操作符<， 比较区间结束时间
bool operator<(const Interval& r1, const Interval& r2) {
  return r1.endTime < r2.endTime;
}
 
class Solution {

private:
  Interval act[MAX_REQ_NUM + 1];      //活动的结构体数组
  int IntervalNum;                    //活动个数
  int p[MAX_REQ_NUM + 1];             //存储与之不相冲突的前一个的活动
  int maxvalue[MAX_REQ_NUM + 1];       //存储最优结果
  int record[MAX_REQ_NUM + 1][2];     //记录活动状态（选或不选）

public:

  void setIntervalNum(const int& IntervalNum) {
    this->IntervalNum = IntervalNum;
  }
  void init() {
    for (int i = 1; i <= IntervalNum; ++i) {
      cout<<"Activity "<<i<<" begintime endtime weight:\n";
      cin >> act[i].beginTime >> act[i].endTime >> act[i].weight;
    }
  }
  // 预备，根据结束时间对所有请求排序，初始化数组p
  void prepare() {
    sort(act+1, act + IntervalNum + 1);
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= IntervalNum; ++i) {
      for (int j = i-1; j > 0; --j) {
        if  (act[j].endTime <= act[i].beginTime) {
          p[i] = j;
          break;
        }
      }
    }
    memset(record, 0, sizeof(record));
  }
  // 动态规划算法
  void solve() {
    maxvalue[0] = 0;
    for (int i = 1; i <= IntervalNum; ++i) {
      if (maxvalue[p[i]] + act[i].weight >= maxvalue[i-1]) {
        maxvalue[i] = maxvalue[p[i]] + act[i].weight;
        record[i][0] = 1;
        record[i][1] = p[i];
      } else {
        maxvalue[i] = maxvalue[i-1];
        record[i][0] = 0;
        record[i][1] = i-1;
      }
    }
  }
  // 输出结果
  void output() {
    cout << "MAX weight: " << maxvalue[IntervalNum]<<endl;
    for(int i = IntervalNum; i > 0; i = record[i][1]) {
      if (record[i][0] == 1) {
        cout << "activity-" << i <<" ";
      }
    }
  }

};

int main() {
  int IntervalNum;
  Solution solution;
  cout<<"Num of activities: ";
  cin >> IntervalNum;
  solution.setIntervalNum(IntervalNum);
  solution.init();
  solution.prepare();
  solution.solve();
  solution.output();
  return 0;
}