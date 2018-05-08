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
	int n = sec.size(), chk=0;
	for (int i=0; i<n; i++){
		if (sec[i].pid <0 ) continue;
		if (sec[i].etime <= time){ 
			sec[i].pid = -1; // end
			sec[i].etime =0;
			chk=1;
		}
	}

 vector<sector>::iterator now = sec.begin();  // merge ~> pid == -1
 while(now != sec.end()){
	 vector<sector>::iterator next = now+1;

	 if (next == sec.end()) break;

	 if(now->pid == -1 && now->pid == next->pid) {
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

	int f = sec[j].f;
	if ( sec[j].sz > proc.sz){ // 만약 섹터가 나눠져야한다면 (proc sz가 좀 덜 필요하다면)
		sec.insert(sec.begin()+j, sector(f, proc.sz, -1, 0)); // j 번쨰 sector 생성!
		sec[j+1].sz= sec[j+1].sz - proc.sz; //sector가 나눠지는거야~
		sec[j+1].f = sec[j].f + proc.sz;
	}

	sec[j].pid = proc.pid; 	 				//set pid
	sec[j].etime = proc.rtime+time; //sector's end time will become proc's require time+nowtime
	return;
}

bool firstfit(process proc, vector<sector>& sec, bool ansChk){ 

	int m= sec.size(), chk=0;  // chk will return if proc is allocated in any sector.
	for (int j=0; j<m; j++){   // then we iterate over memory sector 0 -> m. find first fit
		if (sec[j].pid >= 0) continue; // 이미 할당 되어있으면.

		if (sec[j].sz >= proc.sz) { // if we find a sector that have enough size, 

			insert_sec(proc, sec, j); 
			chk=1; 
			if (ansChk) ans=sec[j].f;
			break;
		}
	}
	return chk;
}

bool bestfit(process proc, vector<sector>& sec, bool ansChk){  // find min diff
	int m=sec.size(), best=1<<29, idx=-1; // best will highlight best sector..

	for (int j=0; j<m; j++){
		if (sec[j].pid>=0) continue;
		if (sec[j].sz<proc.sz) continue; 
		if (sec[j].sz - proc.sz < best) idx=j, best = sec[j].sz -proc.sz;
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

bool fine(vector<bool>& pchk){
	bool chk=0; 
	int n= pchk.size();
	for (int i=0; i<n; i++) if (!pchk[i]) chk=1;
	return chk;
}

int fit(vector<process>& proc, int type){ // time complexity : time * proc * sec(max... 1000) 
																					// but expected complexity is better than array implement..
	vector<sector> sec;
	vector<bool> pchk;
	pchk.resize(proc.size(), 0);

	sec.push_back(sector(0, 1000, -1, 0)); 
	time=0; //  global variable

	int now=0, n = proc.size();

//	while(fine(pchk)){ // while t ~> inf , until "now process iterator" != n...
	while(time<=1000){
		
		for (int i=0; i<n; i++){ // in time t. we iterate over 0 -> n 
			if ( proc[i].stime > time) break; // if proc[i]. start time > nowtime then break;
			if ( pchk[i] ) continue;

			int chk=0;
			if (type == 0) chk = firstfit(proc[i], sec, i==n-1);
			else if (type==1) chk = bestfit(proc[i], sec, i==n-1);
			else chk = worstfit(proc[i], sec, i==n-1);

			if(chk) pchk[i]=1;
		}
		int m = sec.size(); 
		time++;
		endChk(sec); // sector end time chkeck. if we find it over. we make its pid "-1"
	}
	return ans;
}

int main(){
	FILE* fp = fopen("allocation.inp", "r");
	int n; fscanf(fp, "%d", &n);
	vector<process> proc;

	for (int i=0; i<n; i++) {
		int m, k, l; // stime, rtime, size;
		fscanf(fp, "%d %d %d", &m, &k, &l);
		process tmp(m, k, l, i);
		proc.push_back(tmp);
	}
	fclose(fp);
	fp = fopen("allocation.out", "w");
	fprintf(fp, "%d\n", fit(proc, 0));
	fprintf(fp, "%d\n", fit(proc, 1));
	fprintf(fp, "%d\n", fit(proc, 2));
	fclose(fp);
}
