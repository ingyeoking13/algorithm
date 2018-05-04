/*
	 first fit, best fit, worst fit 구현
	 memory 가 유동적으로 조절되는데 , 0~ 999 까지 배열을 선언하는것보다
	 동적으로 설계하는 것이 낫다고 생각했다.

	 C++ STL 에서 제공하는 vector 를 이용하여 0 ~999 를 관리한다.
	 당연히 memory 는 0~999 가 pid -1 로 초기화 되어있으며 <0, -1, 1000> 
	 여기서 300 size 의 process 가 들어오면
	 <0, 0, 300> <300, -1, 700> 가 되는 것이 자명하다.
	 이 것을 vector를 이용하여 구현하였다.

	 struct proc { int stime, rtime, sz, pid; }
	 : 입력 되는 process 이다.

	 struct sector { int f, sz, pid, etime; } 
	 : memory sector이다. 

	 void endchk(vector<sector>& sec, int time)
	 : sector 에서 시간 다 된 sector를 pid -1 로 반환하고, 연결된 sector 끼리 합칩니다.
*/
#include <stdio.h>
#include <vector>
using namespace std;

struct process{ 
	int stime, rtime, sz, pid;  //start time, required time, size, pid
	process(int a, int b, int c, int d ) : stime(a), rtime(b), sz(c), pid(d) {}
};
struct sector{
	int f, sz, pid, etime; // from memory, sz, pid, end time
	sector(int f, int sz, int pid, int et) : f(f), sz(sz), pid(pid), etime(et) {}
};

int ans, time;

void endChk(vector<sector>& sec){ //all sectors will be checked (time) 
	int n = sec.size();
	int chk=0;
	for (int i=0; i<n; i++){
		if (sec[i].pid <0 ) continue;
		if (sec[i].etime == time){ 
			sec[i].pid = -1; // end
			sec[i].etime =0;
			chk=1;
		}
	}

 auto now = sec.begin();  // merge ~> pid == -1
 while(now != sec.end()){
	 auto next = now+1;

	 if (next == sec.end()) break;

	 if( now->pid == -1 && now->pid == next->pid) {
		 now->sz += next->sz;
		 sec.erase(next);
		 chk=1;
	 }
	 else now++;
 }
 if (!chk) return;
 // print...
 printf("========== time : %d\n", time);
 for (int i=0; i<sec.size(); i++){
	 printf("sec from : %d, sec sz : %d, sec pid : %d, sec etime : %d\n", 
			 sec[i].f, sec[i].sz, sec[i].pid, sec[i].etime);
 }
 printf("==========\n");
}

void insert_sec(process proc, vector<sector>& sec, int j){

	if ( sec[j].sz > proc.sz){ // 만약 섹터가 나눠져야한다면 (proc sz가 좀 덜 필요하다면)
		sec.insert(sec.begin()+j, {sec[j].f, proc.sz, -1, 0}); // j 번쨰 sector 생성!
		sec[j+1].sz= sec[j+1].sz - proc.sz; //sector가 나눠지는거야~
		sec[j].sz = proc.sz;  
		sec[j+1].f = sec[j].f + proc.sz;
	}

	sec[j].pid = proc.pid; 	 				//set pid
	sec[j].etime = proc.rtime+time; //sector's end time will become proc's require time+nowtime
	return;
}

bool firstfit(process proc, vector<sector>& sec, bool ansChk){ 

	int m= sec.size(), chk=0;  // chk will return if proc is allocated in any sector.
	for (int j=0; j<m; j++){   // then we iterate over memory sector 0 -> m. find first fit
		if (sec[j].pid >= 0 ) continue; // 이미 할당 되어있으면.

		if (sec[j].sz >= proc.sz) { // if we find a sector that have enough size, 

			insert_sec(proc, sec, j);
			chk=1; 
			if (ansChk) ans=sec[j].f;
		}
		if (chk) break; // if we find sector and alloacate it then go ~>
	}
	return chk;
}

bool bestfit(process proc, vector<sector>& sec, bool ansChk){  // find min diff
	int m=sec.size(), best=1<<30, idx=-1; // best will highlight best sector..

	for (int j=0; j<m; j++){
		if (sec[j].pid>=0) continue;
		if (sec[j].sz<proc.sz) continue; 
		if (sec[j].sz - proc.sz <best) idx=j, best = sec[j].sz -proc.sz;
	}

	if (idx>=0) {
		insert_sec(proc, sec, idx);
		if (ansChk) ans=sec[idx].f;
		return 1;
	}
	return 0;
}

bool worstfit(process proc, vector<sector>& sec, bool ansChk){  // find min diff
	int m=sec.size(), big=-1, idx=-1; // best will highlight best sector..

	for (int j=0; j<m; j++){
		if (sec[j].pid>=0) continue;
		if (sec[j].sz<proc.sz) continue; 
		if (sec[j].sz > big) idx=j, big = sec[j].sz;
	}

	if (idx>=0) {
		insert_sec(proc, sec, idx);
		if (ansChk) ans=sec[idx].f;
		return 1;
	}
	return 0;
}

int fit(vector<process>& proc, int type){ // time complexity : time * proc * sec(max... 1000) 
																					// but expected complexity is better than array implement..
	vector<sector> sec;
	sec.push_back({0, 1000, -1, 0}); 
	ans =-1, time=0; //  global variable

	int now=0, n = proc.size();

	while(now!=n){ // while t ~> inf , until "now process iterator" != n...

		endChk(sec); // sector end time chkeck. if we find it over. we make its pid "-1"
		
		for (int i=now; i<n; i++){ // in time t. we iterate over now -> n 
			if ( proc[i].stime > time) break; // if proc[i]. start time > nowtime then break;

			int chk=0;
			if (type == 0) chk = firstfit(proc[i], sec, i==n-1);
			else if (type==1) chk = bestfit(proc[i], sec, i==n-1);
			else chk = worstfit(proc[i], sec, i==n-1);

			if(!chk) break; // if one process cannot find fine sector, break and time ++
			else now++;
		}

		time++;
	}
	return ans;
}

int main(){
	int n; scanf("%d", &n);
	vector<process> proc;

	for (int i=0; i<n; i++) {
		int m, k, l; // stime, rtime, size;
		scanf("%d %d %d", &m, &k, &l);
		proc.push_back({m, k, l, i});
	}

	printf("%d\n", fit(proc, 0));
	printf("%d\n", fit(proc, 1));
	printf("%d\n", fit(proc, 2));
}
