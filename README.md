# new-sumo-traffic-simulation

跟上一个仿真实验相同，修改了一些错误，解决了一些问题，优化了仿真界面

sumo的安装及使用可观看我的上一个文件

# 基于SUMO的改进Krauss模型仿真

## 1. 研究背景
复现韩光辉等人的论文《基于SUMO平台的微观交通仿真研究》，实现改进的车辆跟驰模型。

## 2. 代码结构

├── intersection.net.xml # 交叉口路网（手动配置的）

├── intersection.rou.xml # 交通流配置

├── ModifiedKrauss.cpp # 改进模型源码

├── analyze.py # 数据分析脚本

└── README.md # 技术文档

## 3. 实验结果
(speed_comparison.png)

## 4. 结论
改进模型有效减少了旅行时间，提升了车辆速度，验证了论文结论

（注：使用Python接口时需要注意环境变量，若不会更改，安装时尽量默认）
