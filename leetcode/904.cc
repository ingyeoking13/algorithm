class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int f=tree[0], s=-1, peg=0, ans=0;
        if (tree.size() ==1) return 1;
        // 내 sequence, f <-- 첫번째 엘리먼트, s <-- 두번째 엘리먼트
        // 반복문을 통해 3가지 경우를 정의
        // 1. f만 있을때 새로운 녀석 만남
        // 2. f, s 있을때 새로운 녀석 만남
        // 3. f나 s에 있는 녀석을 만남
        
        for (int i=1; i<tree.size(); i++)
        {
            if (f != tree[i] && s== -1)  // 아직 나는 f만 가지고 있을때 새로운녀석 나오면
            {
                s=tree[i];               // s에 할당후
                ans = max(i-peg+1, ans); // 기록 갱신
            }
            else if ( f!= tree[i] && s!=tree[i]) //나는 둘다 있는데 새로운 녀석나오면
            {
                int j = i-1;  // 새로운 녀석 바로 이전부터 같을때만 (최대한 길게) 뒤로가서
                int tmp = tree[j];
                while(tmp == tree[j]) j--;
                i=j;            
                
                peg = i+1;      
                f = tree[i+1];  // f 갱신 , s==-1
                s = -1;
            }
            else if (tree[i] == f || tree[i] == s) // 새로운 아이템이 아닐경우
            {
                ans = max(i-peg+1, ans);
            }
        }
        return ans;
    }
};