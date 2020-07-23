<h1>STM8Project</h1>
<p>
  针对全系列STM8编程、编译、烧录的开源开发方法。Editor: VSCode, Compiler: SDCC, Programmer: stm8flash. STM8 open source development method.
</p>
<p>
  工具链：Windows-VSCode-SDCC-make-stm8flash
</p>
<p>
  这个工程最主要的目的是对stm8芯片进行轻量化开发，现在多数初学者开发单片机都是不同芯片装不同IDE，体积臃肿，而且工作后如果从事这一行有可能被查水表。使用该方法可以使得程序全部在VSCode上编辑，只需要安装不同的编译器、烧录器和调试器即可。
</p>
<p>
  VSCode不说了，最强IDE(雾。
</p>
<p>
  SDCC支持多种8位机的编译。<a href="http://sdcc.sourceforge.net/" target="_blank">SDCC官网</a>
</p>
<p>
  stm8flash在GitHub可以下载，但是在Windows环境下使用MinGW64对烧录器进行编译的时候需要修改stm8flash的源代码才能进行编译，我后面会放出修改后的程序，Linux环境下直接make就行了。你也可以自行下载源代码，然后进行更改。<a href="https://github.com/vdudouyt/stm8flash" target="_blank">stm8flash下载地址</a>
</p>
<p>
  debug软件还没找到，openocd不支持stm8，这个后面再说吧。
</p>
<h2>文件树</h2>
<p>
├── README.md
</p>
├── package.json
</p>
└── src
</p>
    ├── common
    </p>
    │   └── XInput.vue
    ├── index.js
    └── utils
        ├── auto-require.js
        ├── index.js
        └── types.js
