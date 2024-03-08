#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Data
{
public:
    int id;
    string value = "EMPTY";
    Data* coreData = NULL;
    vector<Data*> mergedDatas;
    void resetData()
    {
        value = "EMPTY";
        coreData = NULL;
        mergedDatas = {};
    }
    Data(int num) : id(num) {};
    Data* returnCore()
    {
        if (coreData == NULL) return this;
        else return coreData;
    }
    void update(string s) { returnCore()->value = s; }
    void merge(Data* sub, string s)
    {
        Data* core = returnCore();
        sub = sub->returnCore();
        if (core->id == sub->id) return;
        for (auto& data : sub->mergedDatas)
        {
            data->coreData = core;
            core->mergedDatas.emplace_back(data);
        }
        core->mergedDatas.emplace_back(sub);
        sub->mergedDatas = {};
        sub->coreData = core;
        update(s);
    }
    void unmerge()
    {
        Data* core = returnCore();
        for (auto& data : core->mergedDatas)
            data->resetData();
        string s = core->value;
        core->resetData();
        update(s);
    }
    string getValue() { return returnCore()->value; }
};

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<Data*>>datas(50, vector<Data*>(50, NULL));
    int num = 0;
    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 50; ++j)
        {
            datas[i][j] = new Data(num++);
        }
    }

    for (auto& command : commands)
    {
        istringstream ss(command);
        vector<string> temp_vec;
        while (getline(ss, command, ' ')) temp_vec.emplace_back(command);
        if (temp_vec[0].compare("UPDATE") == 0)
        {
            if (temp_vec.size() == 4)
            {
                int a = stoi(temp_vec[1]) - 1; int b = stoi(temp_vec[2]) - 1;
                string s = temp_vec[3];
                datas[a][b]->update(s);
            }
            else
            {
                for (int i = 0; i < 50; ++i)
                {
                    for (int j = 0; j < 50; ++j)
                    {
                        if (datas[i][j]->getValue() == temp_vec[1])
                            datas[i][j]->update(temp_vec[2]);
                    }
                }
            }
        }
        else if (temp_vec[0].compare("MERGE") == 0)
        {
            int a = stoi(temp_vec[1]) - 1; int b = stoi(temp_vec[2]) - 1;
            int c = stoi(temp_vec[3]) - 1; int d = stoi(temp_vec[4]) - 1;
            if (a == c && b == d) continue;
            string s = datas[a][b]->getValue() == "EMPTY" ? datas[c][d]->getValue() : datas[a][b]->getValue();
            datas[a][b]->merge(datas[c][d], s);
        }
        else if (temp_vec[0].compare("UNMERGE") == 0)
        {
            int a = stoi(temp_vec[1]) - 1; int b = stoi(temp_vec[2]) - 1;
            datas[a][b]->unmerge();
        }

        else if (temp_vec[0].compare("PRINT") == 0)
        {
            int a = stoi(temp_vec[1]) - 1; int b = stoi(temp_vec[2]) - 1;
            answer.emplace_back(datas[a][b]->getValue());
        }
    }
    return answer;
}

int main()
{
    solution({ "MERGE 1 1 2 2", "PRINT 1 1" });
}