#include<string>
using namespace std;

int hex2dec(char hex){
  unordered_map<char,int>mp;
	mp['0'] = 0;
	mp['1'] = 1;
	mp['2'] = 2;
	mp['3'] = 3;
	mp['4'] = 4;
	mp['5'] = 5;
	mp['6'] = 6;
	mp['7'] = 7;
	mp['8'] = 8;
	mp['9'] = 9;
	mp['A'] = 10;
	mp['B'] = 11;
	mp['C'] = 12;
	mp['D'] = 13;
	mp['E'] = 14;
	mp['F'] = 15;
  return mp[hex];
}
class Cube{
  private:
    char content[6][3][3];//0= UP;1= Front;2= Left;3= Right;4= Back;5= Down;
  public:
    void fillCube(string Key){
      int counter = 0;
      for (int i = 0; i < 6; i++) {
          for (int j = 0; j < 3; j++) {
              for (int k = 0; k < 3; k++) {
                  content[i][j][k] = Key[counter];
                  counter++;
              }
          }
      }
    }
    
    string getContent(){
      string text = "";
      for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < 3; k++) {
            text+=content[i][j][k];
          }
        }
      }
      return text;
    }

    void printFace(int s){
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          cout<<content[s][j][k];
        }
        cout<<endl;
      }cout<<endl;
    }

    void printAllFaces(){
      for(int face = 0; face<6; face++){
        printFace(face);
      }
    }

    void swap(int face1, int row1, int column1, int face2, int row2, int column2){
      char t1 = content[face1][row1][column1];
      content[face1][row1][column1] = content[face2][row2][column2];
      content[face2][row2][column2] = t1;
    }

    void rotateFace90(int s){
      char t1 = content[s][0][0];//cell pojok
      content[s][0][0] = content[s][2][0];
      content[s][2][0] = content[s][2][2];
      content[s][2][2] = content[s][0][2];
      content[s][0][2] = t1;

      t1 = content[s][0][1];
      content[s][0][1] = content[s][1][0];
      content[s][1][0] = content[s][2][1];
      content[s][2][1] = content[s][1][2];
      content[s][1][2] = t1;
    }

    void rotateFace180(int s){
      char t1 = content[s][0][0];
      content[s][0][0] = content[s][2][2];
      content[s][2][2] = t1;

      t1 = content[s][0][2];
      content[s][0][2] = content[s][2][0];
      content[s][2][0] = t1;

      t1 = content[s][0][1];
      content[s][0][1] = content[s][2][1];
      content[s][2][1] = t1;

      t1 = content[s][1][0];
      content[s][1][0] = content[s][1][2];
      content[s][1][2] = t1;
    }

    void rotateFace270(int s){
      char t1 = content[s][0][0];
      content[s][0][0] = content[s][0][2];
      content[s][0][2] = content[s][2][2];
      content[s][2][2] = content[s][2][0];
      content[s][2][0] = t1;

      t1 = content[s][0][1];
      content[s][0][1] = content[s][1][2];
      content[s][1][2] = content[s][2][1];
      content[s][2][1] = content[s][1][0];
      content[s][1][0] = t1;
    }

    //Rotate Faces 180 degree
    void rotateUp180(){
      rotateFace180(0);//mempengaruhi baris pertama depan, belakang, kiri, kanan
      //pertukaran depan dan belakang( 4= belakang, 1= depan)
      swap(4,0,0,1,0,0);
      swap(4,0,1,1,0,1);
      swap(4,0,2,1,0,2);
      
      swap(2,0,0,3,0,0);
      swap(2,0,1,3,0,1);
      swap(2,0,2,3,0,2);
    }

    void rotateDown180(){
      rotateFace180(5);//mempengaruhi baris terbawah depan, belakang, kiri, kanan
      //pertukaran depan dan belakang( 4= belakang, 1= depan)
      swap(4,2,0,1,2,0);
      swap(4,2,1,1,2,1);
      swap(4,2,2,1,2,2);
      
      swap(2,2,0,3,2,0);
      swap(2,2,1,3,2,1);
      swap(2,2,2,3,2,2);
    }

    void rotateFront180(){
      rotateFace180(1);//mempengaruhi baris terbawah atas, bawah, kiri, kanan
      //pertukaran depan dan belakang( 4= belakang, 1= depan)
      swap(0,2,0,5,0,2);//atas dan bawah
      swap(0,2,1,5,0,1);
      swap(0,2,2,5,0,0);
      
      swap(2,0,2,3,2,0);//kiri dan kanan
      swap(2,1,2,3,1,0);
      swap(2,2,2,3,0,0);
    }

    void rotateBack180(){
      rotateFace180(4);//mempengaruhi baris terbawah atas, bawah, kiri, kanan
      //pertukaran depan dan belakang( 4= belakang, 1= depan)
      swap(0,0,0,5,2,2);//atas dan bawah
      swap(0,0,1,5,2,1);
      swap(0,0,2,5,2,0);
      
      swap(2,0,0,3,2,2);//kiri dan kanan
      swap(2,1,0,3,1,2);
      swap(2,2,0,3,0,2);
    }

    void rotateLeft180(){
      rotateFace180(2);

      swap(0,0,0,5,0,0);//atas bawah
      swap(0,1,0,5,1,0);
      swap(0,2,0,5,2,0);

      //depan belakang
      swap(1,0,0,4,2,2);
      swap(1,1,0,4,1,2);
      swap(1,2,0,4,0,2);
    }

    void rotateRight180(){
      rotateFace180(3);

      swap(0,0,2,5,0,2);//atas bawah
      swap(0,1,2,5,1,2);
      swap(0,2,2,5,2,2);

      //depan belakang
      swap(1,0,2,4,2,0);
      swap(1,1,2,4,1,0);
      swap(1,2,2,4,0,0);
    }

    //Rotate Face clockwise 90 degree
    void rotateFront90(){
      rotateFace90(1);

      char t1 = content[0][2][0];
      content[0][2][0] = content[2][2][2];
      content[2][2][2] = content[5][0][2];
      content[5][0][2] = content[3][0][0];
      content[3][0][0] = t1;
      
      t1 = content[0][2][1];
      content[0][2][1] = content[2][1][2];
      content[2][1][2] = content[5][0][1];
      content[5][0][1] = content[3][1][0];
      content[3][1][0] = t1;

      t1 = content[0][2][2];
      content[0][2][2] = content[2][0][2];
      content[2][0][2] = content[5][0][0];
      content[5][0][0] = content[3][2][0];
      content[3][2][0] = t1;      
    }

    void rotateBack90(){
      rotateFace90(4);
      
      char t1 = content[0][0][0];
      content[0][0][0] = content[3][0][2];
      content[3][0][2] = content[5][2][2];
      content[5][2][2] = content[2][2][0];
      content[2][2][0] = t1;
      
      t1 = content[0][0][1];
      content[0][0][1] = content[3][1][2];
      content[3][1][2] = content[5][2][1];
      content[5][2][1] = content[2][1][0];
      content[2][1][0] = t1;

      t1 = content[0][0][2];
      content[0][0][2] = content[3][2][2];
      content[3][2][2] = content[5][2][0];
      content[5][2][0] = content[2][0][0];
      content[2][0][0] = t1;      
    }

    void rotateUp90(){
      rotateFace90(0);
      
      char t1 = content[4][0][2];
      content[4][0][2] = content[2][0][2];
      content[2][0][2] = content[1][0][2];
      content[1][0][2] = content[3][0][2];
      content[3][0][2] = t1;
      
      t1 = content[4][0][1];
      content[4][0][1] = content[2][0][1];
      content[2][0][1] = content[1][0][1];
      content[1][0][1] = content[3][0][1];
      content[3][0][1] = t1;

      t1 = content[4][0][0];
      content[4][0][0] = content[2][0][0];
      content[2][0][0] = content[1][0][0];
      content[1][0][0] = content[3][0][0];
      content[3][0][0] = t1;      
    }

    void rotateDown90(){
      rotateFace90(5);
      
      char t1 = content[1][2][0];
      content[1][2][0] = content[2][2][0];
      content[2][2][0] = content[4][2][0];
      content[4][2][0] = content[3][2][0];
      content[3][2][0] = t1;
      
      t1 = content[4][2][1];
      content[1][2][1] = content[2][2][1];
      content[2][2][1] = content[4][2][1];
      content[4][2][1] = content[3][2][1];
      content[3][2][1] = t1;

      t1 = content[4][2][2];
      content[1][2][2] = content[2][2][2];
      content[2][2][2] = content[4][2][2];
      content[4][2][2] = content[3][2][2];
      content[3][2][2] = t1;      
    }
    
    void rotateLeft90(){
      rotateFace90(2);
      
      char t1 = content[0][0][0];
      content[0][0][0] = content[4][2][2];
      content[4][2][2] = content[5][0][0];
      content[5][0][0] = content[1][0][0];
      content[1][0][0] = t1;
      
      t1 = content[0][1][0];
      content[0][1][0] = content[4][1][2];
      content[4][1][2] = content[5][1][0];
      content[5][1][0] = content[1][1][0];
      content[1][1][0] = t1;

      t1 = content[0][2][0];
      content[0][2][0] = content[4][0][2];
      content[4][0][2] = content[5][2][0];
      content[5][2][0] = content[1][2][0];
      content[1][2][0] = t1;      
    }

    void rotateRight90(){
      rotateFace90(3);
      
      char t1 = content[0][2][2];
      content[0][2][2] = content[1][2][2];
      content[1][2][2] = content[5][2][2];
      content[5][2][2] = content[4][0][0];
      content[4][0][0] = t1;
      
      t1 = content[0][1][2];
      content[0][1][2] = content[1][1][2];
      content[1][1][2] = content[5][1][2];
      content[5][1][2] = content[4][1][0];
      content[4][1][0] = t1;

      t1 = content[0][0][2];
      content[0][0][2] = content[1][0][2];
      content[1][0][2] = content[5][0][2];
      content[5][0][2] = content[4][2][0];
      content[4][2][0] = t1;      
    }

    //Rotate Face 90 degree counter clockwise(270 degree)

    void rotateFront270(){
      rotateFace270(1);

      char t1 = content[0][2][0];
      content[0][2][0] = content[3][0][0];
      content[3][0][0] = content[5][0][2];
      content[5][0][2] = content[2][2][2];
      content[2][2][2] = t1;
      
      t1 = content[0][2][1];
      content[0][2][1] = content[3][1][0];
      content[3][1][0] = content[5][0][1];
      content[5][0][1] = content[2][1][2];
      content[2][1][2] = t1;

      t1 = content[0][2][2];
      content[0][2][2] = content[3][2][0];
      content[3][2][0] = content[5][0][0];
      content[5][0][0] = content[2][0][2];
      content[2][0][2] = t1;      
    }

    void rotateBack270(){
      rotateFace270(4);
      
      char t1 = content[0][0][0];
      content[0][0][0] = content[2][2][0];
      content[2][2][0] = content[5][2][2];
      content[5][2][2] = content[3][0][2];
      content[3][0][2] = t1;
      
      t1 = content[0][0][1];
      content[0][0][1] = content[2][1][0];
      content[2][1][0] = content[5][2 ][1];
      content[5][2][1] = content[3][1][2];
      content[3][1][2] = t1;

      t1 = content[0][0][2];
      content[0][0][2] = content[2][0][0];
      content[2][0][0] = content[5][2][0];
      content[5][2][0] = content[3][2][2];
      content[3][2][2] = t1;      
    }

    void rotateUp270(){
      rotateFace270(0);
      
      char t1 = content[4][0][2];
      content[4][0][2] = content[3][0][2];
      content[3][0][2] = content[1][0][2];
      content[1][0][2] = content[2][0][2];
      content[2][0][2] = t1;
      
      t1 = content[4][0][1];
      content[4][0][1] = content[3][0][1];
      content[3][0][1] = content[1][0][1];
      content[1][0][1] = content[2][0][1];
      content[2][0][1] = t1;

      t1 = content[4][0][0];
      content[4][0][0] = content[3][0][0];
      content[3][0][0] = content[1][0][0];
      content[1][0][0] = content[2][0][0];
      content[2][0][0] = t1;      
    }

    void rotateDown270(){
      rotateFace270(5);
      
      char t1 = content[1][2][0];
      content[1][2][0] = content[3][2][0];
      content[3][2][0] = content[4][2][0];
      content[4][2][0] = content[2][2][0];
      content[2][2][0] = t1;
      
      t1 = content[4][2][1];
      content[1][2][1] = content[3][2][1];
      content[3][2][1] = content[4][2][1];
      content[4][2][1] = content[2][2][1];
      content[2][2][1] = t1;

      t1 = content[4][2][2];
      content[1][2][2] = content[3][2][2];
      content[3][2][2] = content[4][2][2];
      content[4][2][2] = content[2][2][2];
      content[2][2][2] = t1;      
    }
    
    void rotateLeft270(){
      rotateFace270(2);
      
      char t1 = content[0][0][0];
      content[0][0][0] = content[1][0][0];
      content[1][0][0] = content[5][0][0];
      content[5][0][0] = content[4][2][2];
      content[4][2][2] = t1;
      
      t1 = content[0][1][0];
      content[0][1][0] = content[1][1][0];
      content[1][1][0] = content[5][1][0];
      content[5][1][0] = content[4][1][2];
      content[4][1][2] = t1;

      t1 = content[0][2][0];
      content[0][2][0] = content[1][2][0];
      content[1][2][0] = content[5][2][0];
      content[5][2][0] = content[4][0][2];
      content[4][0][2] = t1;      
    }

    void rotateRight270(){
      rotateFace270(3);
      
      char t1 = content[0][2][2];
      content[0][2][2] = content[4][0][0];
      content[4][0][0] = content[5][2][2];
      content[5][2][2] = content[1][2][2];
      content[1][2][2] = t1;
      
      t1 = content[0][1][2];
      content[0][1][2] = content[4][1][0];
      content[4][1][0] = content[5][1][2];
      content[5][1][2] = content[1][1][2];
      content[1][1][2] = t1;

      t1 = content[0][0][2];
      content[0][0][2] = content[4][2][0];
      content[4][2][0] = content[5][0][2];
      content[5][0][2] = content[1][0][2];
      content[1][0][2] = t1;      
    }

    void scramble(string sub_key){
      for(int a = 0;a<20;a+=2){
        int face = hex2dec(sub_key[a])%6;
        int move = hex2dec(sub_key[a+1])%3; //0 = 90, 1 = 180, 2 = 270
        switch(face){
            case 0:
              switch(move){
                case 0:
                  rotateUp90();
                  break;
                case 1:
                  rotateUp180();
                  break;
                case 2:
                  rotateUp270();
                  break;                       
              }
              break;
            case 1:
              switch(move){
                case 0:
                  rotateFront90();
                  break;
                case 1:
                  rotateFront180();
                  break;
                case 2:
                  rotateFront270();
                  break;                       
              }
              break;
            case 2:
              switch(move){
                case 0:
                  rotateLeft90();
                  break;
                case 1:
                  rotateLeft180();
                  break;
                case 2:
                  rotateLeft270();
                  break;                       
              }
              break;
            case 3:
              switch(move){
                case 0:
                  rotateRight90();
                  break;
                case 1:
                  rotateRight180();
                  break;
                case 2:
                  rotateRight270();
                  break;                       
              }
              break;
            case 4:
              switch(move){
                case 0:
                  rotateBack90();
                  break;
                case 1:
                  rotateBack180();
                  break;
                case 2:
                  rotateBack270();
                  break;                       
              }
              break;
            case 5:
              switch(move){
                case 0:
                  rotateDown90();
                  break;
                case 1:
                  rotateDown180();
                  break;
                case 2:
                  rotateDown270();
                  break;                     
              }
              break;
          }
        }
    }
  //end of public
};