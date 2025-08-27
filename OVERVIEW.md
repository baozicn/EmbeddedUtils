# EmbeddedUtils

EmbeddedUtils 是一组用于嵌入式系统开发的实用组件库，以 C 语言实现，提供常用的队列、日志等功能模块，带有示例演示如何在项目中使用这些模块。设计目标是简单、高效、易于移植，可以直接集成到 STM32、AVR 等单片机工程或裸机/RTOS 项目中。

## 功能模块

- **Logger 日志模块**：提供多级别的日志输出（DEBUG、INFO、WARN、ERROR），可通过 `logger_set_level()` 设置输出等级，并通过字引 `LOG_DEBUG()`, `LOG_INFO()` 等便捷输出格式化字符串。适合调试阶段打印信息或输出关键事件。
- **Queue 循环队列模块**：实现基于数组的循环缓冲区，可用于消息/ 数据缓冲、串号接收缓存等。提供初始化、入队、出队、判空/判满、计数等接口。

后续计划加入更多实用模块，如简单 CLI 命令解析器、CRC 校验、软定时器等。

## 目录结构

```
.
├─┐ include/           头文件，公共 API
│   ├─┐ logger.h       日志模块头文件
│   └─┐ queue.h        队列模块头文件
├─┐ src/               模块实现
│   ├─┐ logger.c
│   └─┐ queue.c
├─┐ examples/          示例工程
│   ├─┐ logger_example/
│   │   └─┐ main.c     演示如何使用日志模块
│   ├─┐ queue_example/
│   │   └─┐ main.c     演示如使使用队列模块
└─┐ README.md          简要介绍（本文件提供更详细说明）
```

## 使用方法

### 集成模块

将 `include/` 和 `src/` 目录加入你的工程中，在编译器的头文件搜索路径中加入 `include` ，并将 `.c` 文件编译进项目即可。不需要使用任何第三方依赖。

### 日志模块示例

```c
#include "logger.h"

int main(void) {
    logger_set_level(LOG_LEVEL_DEBUG); // 设置全局日志等级
    LOG_INFO("System started, version=%d.%d", 1, 0);
    LOG_DEBUG("Debug message: x=%d", 42);
    LOG_WARN("This is a warning");
    LOG_ERROR("Error occurred: code=%d", -1);
    while (1) {
        // ...
    }
}
```

### 队列模块示例

```c
#include <stdio.h>
#include "queue.h"

int main(void) {
    uint8_t buffer[8];
    queue_t q;
    queue_init(&q, buffer, sizeof(buffer));
    // 入队
    for (int i = 0; i < 5; i++) {
        queue_enqueue(&q, i);
    }
    // 出队
    while (!queue_is_empty(&q)) {
        uint8_t val;
        queue_dequeue(&q, &val);
        printf("Dequeued %d\n", val);
    }
    return 0;
}
```

## 贡献和许可

欢迎提交 issue 或 pull request 来完善此仓库。请确保新增代码风格一致并提供相应的示例或文档。

本仓库使用 [MIT License](LICENSE)。
