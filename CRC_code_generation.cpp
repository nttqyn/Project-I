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

string encode_CRC(string data, string generator){
    string added_data = data + string(generator.length()-1, '0');
    string CRC = binary_division(added_data, generator);
    cout << "CRC: "<< CRC << endl;
    return data + CRC;
}

// Hàm sinh chuỗi bit nhị phân 4 bit ngẫu nhiên
string generateRandom4BitString() {
    string bitString = "";
    for (int i = 0; i < 4; i++) {
        bitString += (rand() % 2 == 0) ? '0' : '1'; // Sinh 0 hoặc 1 ngẫu nhiên
    }
    return bitString;
}

int main(){
    string data, generator;
    data = generateRandom4BitString();
    cout << "Enter the binary data (A): " << data << endl;

    cout << "Enter the generator polynomial (g(x)): ";
    cin >> generator;

    string encodedMessage = encode_CRC(data, generator);
    cout << "Encoded message with CRC: " << encodedMessage << endl;

    return 0;
}