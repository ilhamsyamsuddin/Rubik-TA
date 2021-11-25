#include<string>
using namespace std;

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

    void xorCube(Cube c2){
      for (int i = 0; i < 6; i++) {
          for (int j = 0; j < 3; j++) {
              for (int k = 0; k < 3; k++) {
                  content[i][j][k] = content[i][j][k] ^ c2.content[i][j][k];
              }
          }
      }
    }

void get_face_key(string Key){
  int index=0;
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      for(int k=0;k<6;k++){
        content[i][j][k]=Key[index]%6;
        index++;
      }
    }
  }
}

void get_angle_key(string Key){
  int index=0;
  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
      for(int k=0;k<6;k++){
        content[i][j][k]=Key[index]%3;
        index++;
      }
    }
  }
}
  //end of public
};