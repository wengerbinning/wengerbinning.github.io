# Windows API

Windows API是Windows提供的用于应用程序开发的接口。这些接口都被封装在`windows.h`文件中。每一个程序的入口是WinMain()函数。

* 窗口有客户区与非客户区

* 句柄是用于标识资源（窗口、图标、光标等）。

* 消息：Windows会将各类事件封装消息放在队列

## 演示项目

* 演示项目：

  ```c
  int WINAPI WinMain(
      HINSTANCE hInstance,
      HINSTANCE hPrevInstance,
      LPSTR lpCmdLine,
      int nShowCmd
  ) {
      // 设计窗口。
      WNDCLASS wc;
      // 注册窗口
      RegisterClass(&wc);
      // 创建窗口
      HWND hwnd = CreateWindows();
      // 显示和更新
      ShowWindows(hwnd,SW_SHOWNORMAL);
      UpdateWindows(hwnd);
      // 通过循环取消息
      MSG msg;
      while(true) {
          if( GetMessage(&msg,NULL,0,0) == FALSE ) {
              break;
          }
          translateMessage(&msg);
          DispatchMessage(&msg);
      }
      // 处理消息
      return 0;
  }
  ```
