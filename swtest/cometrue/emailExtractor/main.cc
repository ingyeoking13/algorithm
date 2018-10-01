#include "myfunc.cc"

int main() {
	string  pathstr= FILEREAD(); // FILE READ
	ofstream outf; 
	outf.open("C:\\Users\\comtrue\\Desktop\\comtrue.txt");
	outf << "======================================================================== "
					"OUTPUT ====================================================================== \n";
	outf << "[파일 위치]\t\t\t\t[파일명]\t[건수]\t\t[이메일]\n";
	if (is_directory(pathstr)) {
		for (auto& p : recursive_directory_iterator(pathstr)) {
			if (fs::path(p).extension() == ".txt") {
				queue<string> qs; 
				string fPath = p.path().string();
				cout << fPath << "\n";
				int pos = fPath.find_last_of('\\');
				for (int i = 0; i < pos; i++)  outf << fPath[i]; outf << '\t';
				for (int i = pos+1; fPath[i]; i++)  outf << fPath[i]; outf << '\t';
				ifstream inpf; 
				inpf.open(fPath);
				string line;
				while (getline(inpf, line)) {
					int chk = check(line);
					if (chk) qs.push(line);
				}
				int size= qs.size();
				outf << size << "\t\t";

				for (int i = 0; i < size; i++) {
					outf << qs.front();
					if (i < size-1) outf << " ; ";
					qs.pop();
				}
				inpf.close();
				outf << '\n';
			}
		}
		printf("done...\n");
	}
	else { printf("is not a directory.\n"); }
	outf.close();
	getchar();
	getchar();
}
