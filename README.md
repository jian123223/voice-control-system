# 吹气语音控制系统

## 项目简介

为高位截瘫患者开发的吹气控制辅助系统，通过双 INMP441 麦克风采集吹气信号，CH32V307 检测吹气动作并转换为控制指令，经 USB AOA 协议传输至安卓手机，结合无障碍服务实现 App 操作（如微信视频滑动切换）。患者通过"左吹/右吹/中吹"对应不同控制指令。

## 硬件清单

| 模块 | 型号 | 说明 |
|---|---|---|
| 主控 | CH32V307 | 沁恒 RISC-V MCU |
| 麦克风 | INMP441 ×2 | I2S 数字 MEMS 麦克风，双通道采集 |
| 通信 | USB AOA | Android Open Accessory 协议，有线连接手机 |
| 蓝牙 | HC-05 | 备用通信方案，USART3 PB10/PB11 |
| 显示 | OLED | 系统状态显示（吹气能量值等） |

## 技术架构

```
嵌入式端 (CH32V307)
├── 双 INMP441 I2S 采集 — DMA 双通道音频采集
├── 吹气检测算法 — 能量计算 + 阈值判断 + hum 消除
├── USB AOA Host — 与安卓手机建立 AOA 连接
├── OLED 显示 — 实时显示吹气能量 A/B 值
└── HC-05 蓝牙 — 备用通信（USART3）

安卓端 (Kotlin)
├── USB AOA 通信 — 接收 CH32V307 指令
├── 无障碍服务 — 指令映射到 UI 操作
├── 微信控制 — 节点识别 + 手势滑动
└── 悬浮窗 — 显示当前控制状态
```

## 目录结构

```
├── firmware/              # CH32V307 固件（MounRiver Studio 工程）
│   ├── User/              # 主程序入口
│   ├── Phone/             # 手机通信（USB AOA + 吹气检测 + OLED）
│   ├── USB_Host/          # USB Host 驱动（AOA 协议）
│   ├── Peripheral/        # 外设驱动（I2S/UART/SPI等）
│   ├── Core/              # Cortex-M 核心支持
│   ├── Common/            # 通用代码
│   ├── Startup/           # 启动代码
│   ├── Ld/                # 链接脚本
│   ├── .cproject          # MounRiver Studio 工程文件
│   └── .project
├── android/               # 安卓 App（Kotlin + Gradle）
│   ├── app/src/           # 应用源码
│   ├── build.gradle       # Gradle 构建配置
│   └── settings.gradle
└── README.md
```

## 编译与烧录

### 嵌入式固件
1. 使用 MounRiver Studio 打开 `firmware/.project`
2. 编译生成 .hex/.bin
3. 通过 WCH-Link 烧录到 CH32V307

### 安卓 App
1. 使用 Android Studio 打开 `android/` 目录
2. 配置 `local.properties` 指定 Android SDK 路径
3. 编译生成 APK
4. 通过 ADB 安装到手机：`adb install app-debug.apk`

## 使用方式

1. CH32V307 端烧录固件，连接双 INMP441 麦克风
2. USB 线连接 CH32V307 与安卓手机（Type-C）
3. 手机安装 APK，开启无障碍服务
4. 对麦克风吹气即可控制手机 App

## 团队分工

- 嵌入式侧（CH32V307 固件）：刘泽群
- 安卓侧（voice_control App）：队友协作

## 许可证

本项目仅供学习与公益使用。