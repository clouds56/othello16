othello16
=========
[2014年人工智能课程项目-黑白棋16](http://cslab.nju.edu.cn/metis/AI2014.php)

使用方法:
---------
* 将自己写的`othello_ai`类复制到该项目文件夹下
* 修改`main.cpp`中关于`othello_ai`的定义
* 注意此处特别要求成员`othello16 o;`为public
* 如果没有`othello16`成员（没用到sdk）或者不希望他为public请删除54行附近`assert(ai.o.tostring()==o.tostring());`
* 运行时请使用标准输入输出输入对手策略（`x y`的坐标值）
* 任何疑问请联系Clouds.Flowing@gmail.com

本地对战:（支持codeblocks和makefile）
------------------------------------
1. 写两个ai，`ai1.cpp`，`ai2.cpp`
2. Project->Properties->Build targets
  * 新建(Add)两个build target，命名为`ai1`，`ai2`
  * 类型(type)为`Console application`
  * 输出文件(Output filename)为`ai1.exe`，`ai2.exe`
  * 生成目标(Build Target)中去除`ai1.cpp`和`ai2.cpp`防止重复编译
3. Project->Build options
  * `Debug`->Compiler settings->#defines添加`_T_DEBUG`
  * `Release`->Compiler settings->#defines添加`_RELEASE`
  * `ai*`->Compiler settings->#defines添加`_AI*`（把`AI*`替换成`AI1`，`AI2`）
4. Build `ai*`
5. ~~将`runner.py`复制到`ai*.exe`所在文件夹~~**修改`runner.py`中的`pwd`参数为目标文件夹（默认`ai`）**，运行
6. 使用`mathematica`打开`Show.nb`~~修改`pt.log`路径名~~（**先复制到`pt.log`所在目录**）然后运行
  * `mathematica`快捷键snippet
  * 在右边cell上右击`Style`->`InputForm`可以直接整理代码风格
  * 使用右击`Convert To`->`InputForm`或者`StandardForm`也可以完成但是会丢失注释
  * 选中第二段代码，快捷键`Ctrl`+`Shift`+`D`可以将代码分成三段
7. **注意：请将`grep`和`sed`加入系统路径或者自行参考`runner.py`中生成`pt.log`的代码手动生成**
8. 上面的1-4为`codeblocks`步骤，对于`makefile`用户只需修改`Makefile`中`AIDIR`参数，然后运行`make show`即可
