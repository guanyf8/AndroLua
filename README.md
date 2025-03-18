# ParallelLJ

parallelLJ 是一个基于安卓平台的lua-java的多线程库，旨在引入luajava的情况下确保线程安全，同时完善其不具备的多线程能力。

## 模型架构

该项目采用Actor模型，每个线程对应一个独立的lua vm，作为一个独立的actor，通过任务消息队列驱动，每个actor被动唤醒执行任务。我们称这种线程和lua vm为worker

lua vm存在于C层中，每个worker由java层和lua层组成，java层负责线程管理，lua层负责执行任务，因此每个worker有两个任务队列，java层的looper和C层的taskqueue。java层的Looper负责接收信号，转线程和驱动唤醒lua层。lua层被唤醒后从taskqueue中取一个任务根据具体内容进行执行。worker间调用只能使用rpc进行调用。

每个actor也可以自行创建多个task线程，创建轻量级的线程用于并行执行单次简单任务，自动创建和回收线程，使用wait和join进行主actor和task线程的协同。格式类似于pthread。

在此基础上，本项目引入了sharedvalue模块，线程间可以通过访问共享表进行全局数据访问。为最大程度为编程者提供自由，提供了自由的读写锁接口，访问共享表时需要注意线程安全，需要显式地为临界区上锁和解锁。


## 使用方法

### worker创建，调用和销毁
[跳转worker_thread_invoke.lua](./SDK-lua/test/worker_thread_invoke.lua)

### luajava的线程安全回调

[跳转java_object_callback.lua](./SDK-lua/test/java_object_callback.lua)

经过底层通信机制，传输数据时会自动处理引用计数，确保一个java object同一时间只被一个lua_state持有

### task线程创建执行和汇总返回值
[跳转task_thread_test.lua](./SDK-lua/test/task_thread_test.lua)

可以利用此机制做一个树结构的并行计算。

注意每个lua_State的全局变量是独立的，即thread local storage(TLS)，局部变量更是不共享，如有共享需求可以使用共享表。

### 共享变量读写
[跳转shared_set.lua](./SDK-lua/test/shared_set.lua)

[跳转shared_get.lua](./SDK-lua/test/shared_get.lua)