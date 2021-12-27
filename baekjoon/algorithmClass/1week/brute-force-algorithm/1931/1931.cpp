#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

typedef struct _meeting {
    long start;
    long finish;
}meeting;
/*
THis function causes runtime error("segment fault").
because if left < right is true and left > right is true, then this results in runtime error.
bool cmp(const meeting& left, const meeting& right) {
  if(left.finish < right.finish) return true;
  else {
    if(left.start < right.start) return true;
    return false;
  }
  return false;
}
*/
bool cmp(const meeting& left, const meeting& right) {
    if(left.finish == right.finish) return left.start < right.start;
    return left.finish < right.finish;
}

int main(){
    int N;
    long start_, finish_, max_count;
    max_count = 0;
    start_ = 0;
    finish_ = 0;
    meeting input;
    scanf("%d", &N);
    std::vector<meeting> meetings;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &start_, &finish_);
        input.start = start_;
        input.finish = finish_;
        meetings.push_back(input);
    }
    std::sort(meetings.begin(), meetings.end(), cmp);
    long end = 0;
    for(std::vector<meeting>::iterator it = meetings.begin(); it != meetings.end(); it++) {
        if(end <= it->start) {
      max_count++;
      end = it->finish;
    }
  }
  printf("%d\n", max_count);
  return 0;
}

