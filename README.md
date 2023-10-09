# FireflyGodView



# 如何使用（How to use）

## Chinese

1. 下载本插件，放到项目的Plugins文件夹中
2. 右键项目的 `.uproject` 文件，选择 `Generate Visual Studio project files`
3. 打开项目的 `.sln` ，编译生成
4. 找到你项目的 `PlayerController` 的类设置
5. 将 `PlayerCameraManagerClass` 设置为 `BP_FireflyGodViewCameraManager`

## English

1. Download this plugin, put it into the Plugins folder of your project
2. Right-click the `.uproject` file of your project, select `Generate Visual Studio project files`
3. Open the `.sln` file of your project, compile and generate
4. Find the `PlayerController` class settings of your project
5. Set `PlayerCameraManagerClass` to `BP_FireflyGodViewCameraManager`

# 配置文件（Configuration）

## Chinese

上帝视角的配置文件，在插件的 `Content` 文件夹中，是一个名为 `Config_FireflyGodView` 的数据资产

|配置属性|解释说明|
|-|-|
|Enable Camera Initial Location|是否启用摄像机的初始位置|
|Camera Initial Location|摄像机的初始位置，需要 `Enable Camera Initial Location` 设置为true来启用该配置|
|Camera Initial Rotation|摄像机的初始旋转|
|Screen Move Speed|上帝视角的屏幕移动速度|
|Cursor Edge Rate|触发上帝视角屏幕移动的鼠标在屏幕边缘的比例|
|God View FOV|上帝视角的视野范围|

## English

GodView's configuration file, which is in the `Content` folder of the plugin, is a data asset named `Config_FireflyGodView`

|Config Attribute|Description|
|-|-|
|Enable Camera Initial Location|Whether to enable the initial position of the camera|
|Camera Initial Location|Camera 's initial location, this configuration needs `Enable Camera Initial Location` to be set to true to enable it.|
|Camera Initial Rotation|Camera 's initial rotation|
|Screen Move Speed|Screen 's moving speed of god view|
|Cursor Edge Rate|The proportion of the mouse at the edge of the screen that triggers the movement of the screen from God's perspective|
|God View FOV|Field of view of God View|