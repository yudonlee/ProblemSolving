# 알고리즘 결과 매칭 프로그램
매번, 예제 결과와 구현 결과를 비교하는 것은 불필요한 에너지를 소모하기 때문에, 결과 매칭 프로그램을 구현했다.

# 실행 방법

## 1. 소스코드에서 output text file 만들기
결과 매칭을 사용하기 위해선, 소스코드에서 해당 출력 결과를 text file로 가져와야한다. 따라서 main문에 freopen함수를 사용하여, cout으로 출력되는 결과를 text file로 저장한다.        

```cpp
//source code
int main() {
  // ...
  freopen("output.txt", "w", stdout);
  // ...
}
```

## 2. 프로그램 동작 방법
### 해당 프로그램은 argv[1], argv[2]에서 받아온 이름들을 가지고 매칭을 시작한다.   
___실행예시___
```
./judgingProgram exampleOutput.txt myProgramOutput.txt
```
### argv[1], argv[2]에 아무런 입력이 없다면 default로는 "output.txt"와 "result.txt"를 비교한다.
## 결과예시
### Case1) 결과 일치
결과 일치시 "Success"라는 결과가 출력된다.

### Case2) 결과 불일치
결과 불일치 할때, 불일치 된 line들이 출력된다.



