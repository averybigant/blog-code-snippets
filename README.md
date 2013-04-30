blog-code-snippets
==================
这里是我的[博客](http://pc.shu.edu.cn/averybigant)中部分博文的相关代码。
代码可移植性
============
如无特别说明，这里的大多数代码原则上都应该是跨平台的(主指Windows和主流Linux发行版)。python代码应该在安装python解释器和相应库(如opencv, numpy, scipy, python image library等)后可直接运行。<br/>
C/C++代码应该可同时被gcc/g++或者较新版本的Visual Studio正确编译(分别安装了对应的库之后)。<br/>
使用了微软的Kinect SDK,依赖于其私有Kinect驱动的Kinect相关代码根据定义只能在Windows下被正确编译和运行。依赖于libfreenect的Kinect相关代码显然不受此限制。([它们间的比较](http://stackoverflow.com/questions/7706448/official-kinect-sdk-vs-open-source-alternatives))


不过这里的代码大都只在下述环境下被测试过:
Ubuntu12.04 <br />
gcc/g++ 4.6.3<br />
python 2.7.3<br />
opencv 2.3.1<br />


另如无特别说明，这些代码都在MIT协议下被发布。
Author
======
averybigant(averybigant@gmail.com)
LICENSE
=======
Copyright (C) 2013 Yu Renbi

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

