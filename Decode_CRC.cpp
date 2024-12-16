#include<bits/stdc++.h>
using namespace std;

// xor 2 chuỗi cùng độ dài, trả về chuỗi dài n-1
// áp dụng với 2 chuỗi có bit đầu giống nhau
string xor_bit (string a, string b){
    string result = "";
    int n = a.length();

    for(int i = 1; i < n; i++){
        if(a[i]== b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

// chia không nhớ 2 chuỗi bit
string binary_division (string dividend, string divisor){
    int p = divisor.length();

    string tmp = dividend.substr(0, p);
    int m = tmp.length();

    int n = dividend.length();

    while(p<n){                                                     
        if(tmp[0] == '1'){                                          
            tmp = xor_bit(tmp, divisor );       // nếu bit đầu là 1 thì xor với divisor 
            tmp = tmp + dividend[p];            // lấy 1 bit tiếp theo của dividend, tiếp tục chia đến khi lấy bit cuối của dividend
        }else{
            tmp = xor_bit(tmp, string(m, '0')); // nếu bit đầu là 0 thì xor với chuỗi bit 0 ( kết quả loại bỏ được bit 0 đầu )
            tmp = tmp + dividend[p];            // lấy 1 bit tiếp theo của dividend, tiếp tục chia đến khi lấy bit cuối của dividend
        }
        p++;
    }

    // thực hiện xor sau khi lấy bit cuối của dividend
    if(tmp[0] == '1'){
        tmp = xor_bit(tmp, divisor);
    }else {
        tmp = xor_bit(tmp, string(m,'0'));
    }
    return tmp;
}

bool is_error_report(string data, string generator){
    string tmp = binary_division(data, generator);
    if(tmp == string(generator.length() - 1, '0')){
        return false;
    }
    return true ;
}

vector<string> fixed_code(string code, string generator){
    vector<string> valid_codes;
    for(int i = 0; i< code.length(); i++){
        string new_code = code;
        new_code[i] = (new_code[i] == '1' ? '0':'1');
        if(!is_error_report(new_code, generator)){
            valid_codes.push_back(new_code);
        }
    }
    return valid_codes;
}

string decode_CRC(string code, string generator){
    string data = code.substr(0, code.length() - generator.length() + 1);
    return data;
}


int main(){
    string receive_code, generator;
    cout << "Receive Code: ";
    cin >> receive_code ;
    cout << "Enter the generator polynomial (g(x)): ";
    cin >> generator;

    cout << "Is error ?:" ;
    if(!is_error_report(receive_code, generator)){
        cout <<"No" << endl;
        cout << "Data: "<< decode_CRC(receive_code, generator);
    }else{
        cout <<"Yes"<< endl;
        vector<string> fixed_receive_codes = fixed_code(receive_code, generator);
        if(fixed_receive_codes.empty()) {
            cout << "No valid fixed codes found." << endl;
        } else {
            for(const string &code : fixed_receive_codes) {
                cout << "Fixed code: " << code << " - ";
                cout << "Data: " << decode_CRC(code, generator) << endl;
            }
        }
    }
    return 0;
}