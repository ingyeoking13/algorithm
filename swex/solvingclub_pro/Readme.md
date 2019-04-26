# NOTE  

## Heap Sort  

## Quick Sort    

## Merge Sort   

## KMP Algorithm     


## Suffix Array  

`Suffix Array`란, 문자열 `S`가 있을 때 그 접미사들을 정렬해놓은 배열이다.   

|**suffix**|  **i**  |
|:---      | :---: |
|banana|1|
|anana|2|
|nana|3|
|ana|4|
|na|5|
|a|6|

이 때, `i`는 그 접미사의 시작 위치이다.  
이를 `Suffix string` 순으로 정렬하면 아래와 같다.  

|**suffix**|  **i**  |
|:---      | :---: |
|a|6|
|ana|4|
|anana|2|
|banana|1|
|na|5|
|nana|3|

정렬된 `i`의 배열 `[6, 4, 2, 1, 5, 3]`을 `S`의 `Suffix Array`라고 한다.    
문자열 `S`의 `LCP Array`는 `Suffix Array`를 구한 다음, 각 정렬된 `Suffix` 상태에서 바로 이전 `Suffix` 상태와의 `LCP (Longest Common Prefix)`의 길이를 배열에 담은 것이다.   

* `LCP`란, 문자열 |S|의 위치 p1, p2가 있을 때, [p1, p1 + l - 1] == [p2, p2 + l - 1]을 만족하는 가장 긴 l을 쿼리당 빠르게 구할 수 있는가? 라는 문제에서 활용된다.    
위의 예에서 `LCP Array`는 `[x, 1, 3, 0, 0, 2]`가 된다. 따라서, 최장 공통 접두사 길이는 `3`이다.     

### WHY?    

공통 부분 접두사를 이렇게 구할 수 있는 이유는, `Suffix Array`는 사전순으로 정렬되어 있기 때문이다.  
따라서, `Suffix Array`의 각 원소(`suffix string`) 들의 일부 접두사가 반복해서 출현한다면, 항상 서로 이웃하면서 발견된다.   
위 예처럼, `((ana, anana)의 ana, (na, nana)의 na)`가 공통 부분 문자열이 되는 것이다.   

### HOW?  

이제 먼저 `Suffix Array`를 만드는 방법에 대해 이야기 한다.  
단순히, `n`개의 `string`을 정렬하는 방법이 있다. 그러나, 이 방법은 O(N<sup>2</sup>log n)이다. [백준:접미사배열](https://www.acmicpc.net/problem/11656)   

단순히 정렬하는 것이 아니라, `1, 2, 4 ... 와 같이 2의 배수`로 `counting sort`로 정렬하면, 시간복잡도를 확연히 줄일 수 있다.   
단, 기준이 되는 것은 문자열으로써의 `counting sort`이지만, 실제 알고리즘에서 비교하는 것은 `integer`이다. 따라서, `log n`번 수행하는 `n log n` 정렬이므로, O(n log<sup>2</sup>n)이 되는 것이다.  

소스참조 : suffix.cc  참조.  

매 루프 마다, 카운팅 정렬을 하는 것이 인상적이다.  
ind 배열은 원래 해당 문자가 어느 자리에 있었는지 그리고 정렬 후 어디에 위치 하고 있는지 저장  
해놓는다.  
suffix 구조체는, 자신 알파벳의 위상 rank[0]과 자신 인덱스 + k 만큼 이동한 (카운팅 정렬의 base와 비슷한 개념)  
알파벳의 위상 rank[1]을 이용하므로 그 두개를 적절히 사용한다.  

geeks for geeks에서 참조하여 조금 수정하였다.  
koosaga님, 전명우님 블로그나, 백준님 소스는 다 다른데,  구현에 있어 쉬움은 백준님 것이지만,  
람다 함수를 포함하기 때문에 특히 swexpert 기준 람다를 지원하지 않기 때문에 geeks for geeks 소스로 사용한다.  
내가 볼땐 4개 중에서 제일 이해하기 쉽다라고 생각한다. 기존 geeks for geeks 소스도 약간 손을 봐야하긴 하지만 ... 

