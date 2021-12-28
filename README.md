# Rubik-TA
Program ini merupkan cipher berdasarkan kubus rubik. Pada program ini, plaintext, kunci, dan ciphertext dipresentasikan dalam hexadesimal. Cipher menerima input 216 bit plaintext dan 216 bit kunci.

<h3>Gambaran umum algoritma:</h3>

1. Key Expansion. round key diturunkan dari dari kunci. kunci dan Round key sebesar 216 bit. ada 10 round key yang dihasilkan, satu untuk setiap putaran.
2. input di XOR dengan key
3. Round Function, yang setiap tahap terdiri dari
   1. SubBytes. bit-bit  input disubstitusikan berdasarkan S-Box. 
   2. Scramble. pada langkah ini, input dimasukkan ke dalam struktur kubus rubik 3x3x3, yang setiap selnya memuat 4 bit(3x3x6x4=216),  kubus diacak berdasarkan round key, kecuali putaran pertama yang menggunakan kunci.
   3. Subbytes. hasil scramble di-XOR-kan dengan round key.

<h3>Struktur Rubik</h3>
Struktur Rubik merupakan kubus yang memiliki enam permukaan, dengan setiap permukaan memiliki sembilan sel yang disusun dalam tiga baris dan tiga kolom. Dipresentasikan dalam program sebqagai array tiga dimensi berukuran 6x3x3. 

![image](https://https://github.com/ilhamsyamsuddin/Rubik-TA/blob/main/Jejaring.jpg?raw=true)
<h4>gambar struktur kubus dan index masing-masing sel</h4>
Setiap sel memuat empat bit, yang dipresentasikan dalam bilangan hexadesimal.
