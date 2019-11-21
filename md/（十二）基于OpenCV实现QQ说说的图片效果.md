#### 基于OpenCV实现QQ说说的图片效果
###### 问题
将一张图片的后缀改成其他，或者去掉之后opencv是否能正确的读出
```c++
Mat src = imread("C:/Users/ubt/Desktop/test.jpg");
Mat src = imread("C:/Users/ubt/Desktop/test.txt");
```
将后缀改成txt后能读出正确的图片吗？为什么？</br>
测试过后是可以的</br>
文件的读取是以流的形式，流中包含了一些图片的信息，如头信息（文件的格式，大小，等等），调色信息（怎么压缩的，压缩过后该怎么还原），压缩数据，所以无论有没有后缀，以流的新式都能读取到正确的图片。</br>
