#include <vector>

class KiwiJuice{
	public:
		vector <int> a(vector <int> capa,
			 						 vector <int> bot,	
									 vector <int> from,
									 vector <int> to){

			for (int i=0; i<from.size(); i++){
				bot[to[i]] += bot[from[i]];
				bot[from[i]] = 0;
				if ( bot[to[i]] > capa[to[i]] ) 
					bot[from[i]]+= bot[to[i]]-capa[to[i]],bot[to[i]]=capa[to[i]];
			}
			return bot;
	}
};
