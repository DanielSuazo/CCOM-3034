#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'numberOfTokens' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER expiryLimit
 *  2. 2D_INTEGER_ARRAY commands
 */
struct Token {
    int expiryDate = 0;
    int tokenId;
    Token(int id, int eD) : tokenId(id), expiryDate(eD) {}
};

int indexOf(int id, vector<Token*> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] && tokens[i]->tokenId == id) return i;
    }
    return -1;
}

int numberOfTokens(int expiryLimit, vector<vector<int>> commands) {
    vector<bool> unique(99999, 0);
    vector<Token*> tokens;
    vector<int> last;
    for (auto c: commands) {
        if (c[0] == 0 && !unique[c[1]]) {
            tokens.push_back(new Token(c[1], c[2] + expiryLimit));
            unique[c[1]] = 1;
        } else if (c[0] == 1) {
            int index = indexOf(c[1], tokens);
            // cout << "Date: " << tokens[index]->expiryDate << " > " << c[2] << endl;
            if (index == -1) {

            } else if (tokens[index] && tokens[index]->expiryDate >= c[2]) {
                tokens[index]->expiryDate += expiryLimit;
            }
            last = c;
        }
    }
    for (int i = 0; i < tokens.size(); i++) {
        while (tokens[i] && tokens[i]->expiryDate < last[2]) {
            delete tokens[i];
            tokens.erase(tokens.begin() + i);
        }
    }
    return tokens.size();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string expiryLimit_temp;
    getline(cin, expiryLimit_temp);

    int expiryLimit = stoi(ltrim(rtrim(expiryLimit_temp)));

    string commands_rows_temp;
    getline(cin, commands_rows_temp);

    int commands_rows = stoi(ltrim(rtrim(commands_rows_temp)));

    string commands_columns_temp;
    getline(cin, commands_columns_temp);

    int commands_columns = stoi(ltrim(rtrim(commands_columns_temp)));

    vector<vector<int>> commands(commands_rows);

    for (int i = 0; i < commands_rows; i++) {
        commands[i].resize(commands_columns);

        string commands_row_temp_temp;
        getline(cin, commands_row_temp_temp);

        vector<string> commands_row_temp = split(rtrim(commands_row_temp_temp));

        for (int j = 0; j < commands_columns; j++) {
            int commands_row_item = stoi(commands_row_temp[j]);

            commands[i][j] = commands_row_item;
        }
    }

    int result = numberOfTokens(expiryLimit, commands);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}