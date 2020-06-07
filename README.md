# myblock（我罗斯方块）
The oop homework,which need to program a game called mybloce(我罗斯方块).

游戏内容
基础内容与俄罗斯方块一样。
俄罗斯方块
区别在于，我罗斯方块是同屏幕，双人对战游戏，双方一人使用 wasd ，一人使用上下左右控制，当一名玩家消去一行，就会让另一名玩家最底下增加随机一行。

详细
以玩家一为例，AD 控制方块左右移动，W 转换方块朝向，S 快速下落，使得方块落到底端。当玩家方块填满一整行时，会消除这行方块，然后使得玩家二的方块底部随机增加一行带空格的。玩家二同理。当一名玩家方块高度达到一个高度时就会结束游戏，该玩家失败。

说明：
-
1.游戏开始

按回车后游戏开始，方块自动下落

2.移动

玩家1使用“A”键，玩家2使用”⬅“操作方块左移。

玩家1使用“D”键，玩家2使用”➡“操作方块右移。

玩家1使用“S”键，玩家2使用”⬇“操作方块加速下落。

玩家1使用”W“键，玩家2使用“⬆”操作方块变形。

3.增行规则解释

当一名玩家消去一行后，另一名玩家会在底部随机生成由空白和方块组成的一行。

4.操作缺陷解释

当一名玩家长按某一方向操作键时，会影响另一玩家的相同操作。暂时无法解决，所以使用方向键时禁止长按按键。

存在问题：
-
1.存在当从底部增加一行时可能使新生成方块部分缺失的bug

2.尚未完成游戏菜单的创建

3.游戏结束后没有重新开始游戏的功能
