# <i style="display:none;">TOP</i>  
> -----------------------------------------------------------------------------------------------------  
>   [![TouchCal logo](./extras/favicon.ico "TouchCal Github Page")](http://guerratron.github.io/TouchCal "TouchCal Web")  
> '**TouchCal**' (Arduino Library) &emsp;-&emsp; TouchCal Mini-library for SPI touch screens (XPT2046_Touchscreen) - by GuerraTron24
> By:  Juan José Guerra Haba - <dinertron@gmail.com> &emsp;-&emsp; Feb, 2023  
> Web:     [GrTron.es][authorWeb] , [GuerraTron.github][authorWeb2]  
> License: Apache + Open GPL v.3. Keep credit, please.   
> Versión: 1.0.0  
> Proyect:    Touch-Screen C++ &emsp; Package: TouchCal.h &emsp; Namespace: tc  
> 
> ----------------------------------------------------------------------------------------------------  

<h3 id="TOC">🏠︎ TOC 🖇️ (Contents Table)</h3>

- [📋 Introduction](#📋-intro)
- [🔧 Use](#🔧-use)
- [✨ Improvements](#✨-improvements)
- [⌨️ Preview](#⌨️-preview)
- [💣 Fixs](#💣-fixs)
- [🔗 Depends](#🔗-depends)
- [🌍 Sources](#🌍-sources)
- [🎁 Acknowledgements](#🎁-acknowledgements)
- [✒️ Sign](#✒️-sign)

<p class="entities" style="display:none;">📋 🔧 ⌨️ ⌨ 🖮  ⚙️ 🚀 📌 ✒️ 🎁  ⎃ ⌂ ☗ 🏠︎ 🏚️ 🏠 ♥ ❤ ❤️ 💖 ★ ⍟ ✨ ⭐ ⭕ 
〽️ ♯ ☑️ ✔️ ✓ ✗ ✖️ ❌ ❗ ❕ ❓ ❔ ⍰ ⯑ 🛈 ⚠ ⚠️ ⚿ ⛔︎ ⛔ 💣 🎈 🔡 🔣
‖ ” „ ƒ ∀ ⌬ ∅ ♖ ♜ 🏆︎ 🏆 🎰 🎮 🎖 🎖️ 🏅
🜉 ⌁ ⭍ 🗲 🗱 ⚡ ⍾ ⏚ ⏛ ⏦ 〰 ♒︎ ☁  ➕ ➖
⌛︎ ⏳︎ ∵ ⛬ 🝆 ⋙ ⭆ ⟹ ⇨ ⊳ ⌲ ➤ ⬀ 🔝 ∭ ↺ ⮔ 🔄 ∾ ∞ ⋈ ♾ ⊕ ⊚ ⌾ 🞇 ⬤ ⏺ ⚫︎ 🞑 🅢 🆂 Ⓢ 🅂 ╬ ⋮ Ξ π ω Ω ⅏ 🀰 🙼 🙾 
⛿ ⚐ ⚑ ⛳︎ 🏳️ 🏴 🏷️ ⚒ 🛠 ⚒️ ⚙ ⛯ ⛓ ⛓️ 🔗 ⛶ ⯐ ✉ ✉️ 📧 🌍︎ 🌍 ✎ ❒ 𝄝 𝄜 🎵 ☺ ☻ ☹ 👤 👦 💥 💤
🜲 🌡 🎚 🎚️ 📷︎ 📷 👁 👁️ 👀 📤︎ 📥︎ 🔓︎ 🔒 🔑 🕨 🕪 🔇 🔈 🔊 🕭 🔔 🔕 🕮 📖 🖋 🖈 📌 📎 📏 🖑 🖫 💾 🗎 📄 🗀 🗁 🗑 🗓 📆 📅 
📟 🗗 🗠 📈 📊 🗩 💬 📦 💯 🔋 🔎</p>
<style>
    blockquote{
        text-align: center;
    }
    .info{
        background:lightBlue;
        color: #333333;
    }
    .alert{
        border-radius: 6px;
        font-size: 0.6em;
        color: blue;
        background: navajoWhite;
        padding: 10px;
    }
    .green{
        color: navy;
        background: lightGreen;
    }
    .preview{
        width: 100%;
        cursor: pointer;
    }
    .mini-preview{
        width: 25%;
        cursor: pointer;
    }
    .bg-SERVICER{
        border-radius: 10px;
        padding: 5px;
        margin: 5px;
        color: lightBlue;
        background: navy;
    }
    .bg-SERVICER>ul>li>i, .bg-FREEDER>ul>li>i{
        background-color: lemonchiffon;
        color: red;
        padding: 0 4px;
        margin-right: 5px;
        line-height: 1.3em;
    }
    .bg-FREEDER{
        border-radius: 10px;
        padding: 5px;
        margin: 5px;
        color: lime;
        background: darkgreen;
    }
    .float-left{
        float: left;
    }
    .clearfix{
        clear: both;
    }
    .small{
        font-size: x-small;
        color: gray;
    }
    h1{
        text-align:center;
    }
    h2>span{
        float:left;
    }
</style>

# ![TouchCal logo](./extras/logo.png "logo") TouchCal v1.0 <span class="small">by [GuerraTron-24][authorEmail]</span>

## 📋-Intro

 Mini-library for SPI touchscreens (needs XPT2046_Touchscreen).

It has utilities for the TouchScreen such as screen calibration, checking valid touch based on pressure,
Lissajous figures to check screen symmetry, and even "Dark-Mode" without display ..

> Based on the examples from the **TFT_eSPI** library by *bodmer*; uses **XPT2046_Touchscreen** by *Paul Stoffregen*. *(WHAT A WONDERFUL UTILITIES)*.

Although it is more visual and aesthetic to use a display, there are actually projects where they are not essential. That is why this
library has NO DIRECT DEPENDENCE with *TFT_eSPI*, you can work without that "wonderful utility" (but you can with *XPT2046_Touchscreen*).

This mini-library arises from the need to obtain touch screen configuration parameters as a result of
some experiments in which the original function ``` TFT_eSPI::calibrateTouch(..) ``` failed, the device
would hang with certain screen, pin and SPI configurations.

I have made the calibration function more visual even though it increases the computational cost, since it is
not supposed to be a user library in the usual sense, but rather a tool for the programmer who
will surely inhibit it when the debugging is finished.


## 🔧-Uso

 The main function would be *"calibration(..)"* which takes as parameters (POINTERS) the touchscreen and the screen (if available),
as well as colors and sizes for the corner arrows (just like *"TFT_eSPI::calibrateTouch(..)"*).
The function performs the same checks as the original plus some extra additions, but relies on the *touchscreen* object
passed as a parameter and which is supposed to be already initialized to detect touches, instead of the default object
that the original library attacks.

> Thus, with this library it DOES NOT MATTER which pins the touchscreen is connected to, nor what type of *SPI* it uses, since this is 
> established prior to using this library. The screen parameter (TFT_eSPI \*tft) is used to display the indications and the read data, 
> although it is not essential since the same data is being sent in parallel to the serial monitor *(what a curious expression, "parallel-serial"!)*, 
> and can even be obtained at runtime through the global array ``` TC_PARS\[5\] ```.

What is needed are the screen dimensions: *TFT_HEIGHT* and *TFT_WIDTH*, and the predefined colors, as well as the rotation
*TC_ROTATION*; depending on this rotation the values ​​of "width" and "height" will be inverted.

- **FULL-MODE**: Use for example: ``` tc::calibration(&ts, &tft); ```
A normal use would be its use in the "setup" after having initialized the rest of the necessary *"Serial, TFT_eSPI, XPT2046_Touchscreen"*
libraries; or for example also in a *"handler"* of some action button.

- **DARK-MODE**: A simplified use could be using only the "touchscreen" (without screen) for which it would be necessary to
previously define some definitions used by the *"TFT_eSPI"* library (dimensions and colors), then it would be reduced to:
``` tc::calibration(&ts); ```

- **PIN-MODE**: Another work mode (*EXTREME*), without display or Serial port, could be implemented by reporting through an *LED* connected to the pin defined in
*PIN_PRINT*, by default 26 in ESP32. This method is very archaic but it would be useful to identify touches in the corners based on the blinking of the *LED* (corner1 = 1, corner2 = 2, ..) and we would only need the touch part of the screen. From here the touch part would be calibrated, but of course, each time we start it we would have to recalibrate it again.

ATTENTION: Define the rotation to be used with the screen and the touch in *TC_ROTATION* (from 0 to 3)
 

## ✨-Mejoras
Future improvements are planned in later versions, perhaps more drivers and support for more screens, new functions, perhaps change from *namespace* to *class*, separation into source files and header, ... Future improvements are planned in later versions, perhaps more drivers and support for more screens, new functions, perhaps change from *namespace* to *class*,
separation into source files and header, ...
 
It has only been tested on a board with **ESP32** (*DOIT ESP32 DevKIT v1*) and  *TFT-SPI 3.2" - 240x320*
 
## ⌨️-Preview
![TouchCal Preview 1](./extras/preview.png "preview")
![TouchCal Preview 2](./extras/preview2.png "preview2")
<blockquote>
<img class="mini-preview" src="./preview.png" title="click for preview" onclick="this.classList.toggle('mini-preview'); this.classList.toggle('preview');" />
</blockquote>

## 💣-Correcciones
TODO: Code improvement and refactoring, bug fixes, ..
EVERYTHING HAS BEEN IMPLEMENTED IN A SINGLE ".H" HEADER FILE DUE TO NUMEROUS PROBLEMS IN THE "LINKER" WHEN SEPARATING IT INTO ".cpp" FILES

## 🔗-Dependencias
It has a direct dependency on **"XPT2046_Touchscreen"**  
Although it does NOT have a DIRECT DEPENDENCE on *"TFT_eSPI"* (you can work without that "wonderful utility") the truth is that the experience improves quite a bit with it.

### 🌍-Fuentes
[TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) de *Bodmer*,  
[XPT2046_Touchscreen](https://github.com/PaulStoffregen/XPT2046_Touchscreen) de *Paul Stoffregen*,  
https://forum.arduino.cc/, ..

### 🎁-Agradecimientos
Many thanks to all those who make free code for developing super useful tools for everyone; this time also to Microsoft for its <abbr title="Visual Studio Code">VSC</abbr>, 
without this tool the creation of the library would have been impossible.  
.. and in general to all the altruistic world that generates code and makes it open-source. Also to the world of **Arduino** and open-hardware.

## ✒️-Sign:
Enjoy using it. I hope someone finds it as useful as I did.

2024 - ![TouchCal logo](./extras/toroBot.png "GuerraTron-Bot") [GuerraTron-24][authorEmail] &reg; [GuerraTron Github][authorWeb2]

---
⌨️ con ❤️ por [Juan José Guerra][GuerraTron-Github] 😊

[<b style="font-size:xx-large; margin-left:50%;">🔝</b>](#top)

<!-- REFERENCIAS -->
[authorEmail]: mailto:dinertron@gmail.com  
[authorWeb]: https://grtron.es/ "Desarrollo web + app"  
[authorWeb2]: https://guerratron.github.io/  
[GuerraTron-Github]: https://github.com/guerratron/  
