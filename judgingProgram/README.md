# 알고리즘 결과 매칭 프로그램
매번, 예제 결과와 구현 결과를 비교하는 것은 불필요한 에너지를 소모하기 때문에, 결과 매칭 프로그램을 구현했다.
# 컴파일 환경
__-std=c++98__
# 실행 방법

# 1. 소스코드에서 output text file 만들기
결과 매칭을 사용하기 위해선, 소스코드에서 해당 출력 결과를 text file로 가져와야한다. 따라서 main문에 freopen함수를 사용하여, cout으로 출력되는 결과를 text file로 저장한다.        

```cpp
//source code
int main() {
  // ...
  freopen("output.txt", "w", stdout);
  // ...
}
```

# 2. 프로그램 동작 방법
## argv[1] , argv[2]에 원하는 text file 이름 입력
해당 프로그램은 argv[1], argv[2]에서 받아온 이름들을 가지고 매칭을 시작한다.   
___실행예시___
```
./judgingProgram exampleOutput.txt myProgramOutput.txt
Success!
```
## argv[1], argv[2]에 아무런 입력이 없다면 default로는 "output.txt"와 "result.txt"를 비교한다.
```
./judgingProgram 
Success!
```
# 3.결과예시
## Case1) 결과 일치
결과 일치시 "Success"라는 결과가 출력된다.

### Case2) 결과 불일치
결과 불일치 할때, 일치하지 않는 Line의 line number와 text file들의 내용이 출력된다.   
이때, 한쪽 text file에서 한쪽의 길이가 더 긴 경우, 일치하지 않는 전체 Line이 출력되기 때문에 전체가 출력된다.
```txt
//test1.txt
line1
line2
```

```txt
//test2.txt
line1
line2
line3
```

```
./judgingProgram test1.txt test2.txt 
line number: 3
file name: test2.txt content: line3
```


