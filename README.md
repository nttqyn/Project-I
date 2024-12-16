# Project-I

Thuật toán sinh mã, giải mã phát hiện lỗi CRC(7,4)

Mô tả: Thuật toán mã hóa của mã chống nhiễu CRC (n,l) là tạo từ mã nhị phân dài n bit X = x1x2..xn từ độ hợp mang tin nhị phân dài l bit A = a1a2..al như sau: Dịch chuyển tổ hợp mang tin l bit sang trái n-l vị trí rồi chia kết quả dịch trái này cho tổ hợp nhị phân dài n – l + 1 bit g(x) = g1g2..gn-l+1 (còn gọi là đa thức sinh bậc n-l) cho trước. Số dư của phép chia này gọi là CRC. Từ mã là tổ hợp mang tin nối thêm CRC (dạng từ mã (Information, CRC và là phần than của đa số các giao thức truyền thông hiện nay).

Thuật toán giải mã là từ tổ hợp nhị phân nhận được dài n bit Y = y1y2..yn tính dấu hiệu phát hiện sai S = Số dư của phép chia Y cho g(x). Nếu S = 0 thì tổ hợp nhận được là từ mã đúng. Nếu S <> 0 thì từ mã sai. Để sửa sai trong trường hợp kênh chỉ gây ra nhiều nhất 1 vị trí sai trên một từ mã truyền qua nó có thể dùng thuật toán: chia các tổ hợp nhị phân dài n trong đó chỉ có 1 vị trị sai (các tổ hợp gây sai chỉ một vị trí cho một từ mã dài n) và tìm số dư ta được các dấu hiệu sai vị trí i (tập hợp {Si}). Khi tính dấu hiệu phát hiện sai xong, kiểm tra nó trùng với Si nào thì tổ hợp nhân được bị sai ở vị trí i. Sửa sai bằng cách đổi giá trị nhị phân của vị trí sai.

Đề 13.a: Yêu cầu tìm thuật toán chi tiết và viết chương trình nhập tổ hợp mang tin có , đa thức sinh và tính ra từ mã. Thử nghiệm với CRC (7,4) và đa thức sinh g(x) = 1011. Đề 13.b: Yêu cầu tìm thuật toán chi tiết và viết chương trình nhập tổ hợp nhận được, đa thức sinh và giải mã cho mã CRC. Thử nghiệm với CRC (7,4) và đa thức sinh g(x) = 1011.
