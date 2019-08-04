#include<bits/stdc++.h>
using namespace std;

int cache_id;
int calc_max(string ori){
    int full_length = ori.size();
    int ret = 0;
    int cut_length;
    for (int id = 0; id < 3; id++){
        for (int cut_length = 0; cut_length <= full_length; cut_length ++){
            // cout<<char('A'+id)<<" at "<<cut_length<<endl;
            // cout<<ori<<endl;
            int tmp_ans = 0;
            string m_str = ori.substr(0, cut_length) + char('A'+id) + ori.substr(cut_length);
            // cout<<m_str;
            int start = 0;
            bool unfound = 0;
            while (true){
                bool found = 0;
                if (m_str.size() <= 1) break;
                if (start >= m_str.size()) start = 0;
                for (int i=start;i<m_str.size()-1;i++){
                    if (m_str[i] == m_str[i+1]){
                        start = i;
                        found = 1;
                        break;
                    }
                }
                if (unfound && !found ) break;
                if (!found){
                    unfound = 1;
                    start = 0;
                    continue;
                }
                else {
                    unfound =0;
                }
                int end_ = start;
                for (int i=start+1; i<m_str.size(); i++){
                    if (m_str[i] == m_str[start]){
                        end_ = i;
                    }
                    else break;
                }
                tmp_ans += end_ - start + 1;
                m_str = m_str.substr(0, start) + m_str.substr(end_+1);
            }
            // cout<<" "<<tmp_ans<<endl;
            if (tmp_ans > ret) {
                ret = tmp_ans;
            }
        }
    }
    return ret;
}


int main(){
    int num;
    cin >> num;
    string origin_str;
    while (num--){
        cin >>  origin_str;
        cout<< calc_max(origin_str) << endl;
    }
}