#include <iostream>
using namespace std;
class Music {
    public:
        string nome;
        int tempo = 0;
        int total = 0;
        int key = 0;
        Music(string s, int t) {
            nome = s;
            tempo = t;
        }
        void Increment() {
            total += tempo;
        }
};

int main() {
    int M, t, count = 0;
    string input = "Begin", s;
    Music *spotify = nullptr, *hash = nullptr;
    cin >> M;

    spotify = (Music*) calloc(M, sizeof(Music));
    if (spotify == nullptr) {
        cout << "Chorou" << endl;
        exit(1);
    }

    hash = (Music*) calloc(500, sizeof(Music));
    if (hash == nullptr) {
        cout << "Chorou3" << endl;
        exit(1);
    }

    while (input != "END") {
        cin >> input;
        if (input == "ADD") {
            count++;
            bool verif = false;

            if (count-1 > M/2) {
                M = M*2 + 1;
                spotify = (Music*) calloc(M, sizeof(Music));
                if (spotify == nullptr) {
                    cout << "Chorou2" << endl;  
                    exit(1);
                }  
                for (int i = 0; hash[i].tempo != 0; i++) {
                    verif = false;
                    for (int j = 0; verif != true; j++) {
                        int pos = (hash[i].key + j) % M;
                        if (spotify[pos].tempo == 0) {
                            spotify[pos].tempo = t;
                            verif = true;
                        } 
                    }
                }
                verif = false;
            }
            cin >> s >> t;
            int key = 0;
            for (int i = 0; i < s.length() ; i++) {
                key += s[i]*i;
            }

            for (int i = 0; verif != true; i++) {
                int pos = (key + i) % M;

                if (spotify[pos].tempo == 0) {
                    spotify[pos].tempo = t;

                    hash[count-1].nome = s;
                    hash[count-1].tempo = t;
                    hash[count-1].key = key;

                    cout << s << " " << pos << endl;
                    verif = true;
                } 
            }
        } else if (input == "PLAY") {
            cin >> s;
            for (int i = 0; i < M; i++) {
                if (s == hash[i].nome) {
                    hash[i].Increment();
                    cout << hash[i].nome << " " << hash[i].total << endl;
                    i = M;
                }
            }  
        } else if (input == "TIME") {
            cin >> s;
            for (int i = 0; i < M; i++) {
                if (s == hash[i].nome) {
                    cout << hash[i].nome << " " << hash[i].total << endl;
                    i = M;
                }
            }
        } else { free(spotify); free(hash); }
    }
}