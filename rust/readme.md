# WASM DEMO: rust
I am creating a bunch of small wasm demo's, to show the different methods of creating wasm-powered web libraries. 
This one uses rust, and rust's recommended methods of translating between the two.

# PRO
- VERY EASY to set up and get working. 
- Excellent documentation
  - the `game of life ` tutorial is very thorough on what you might encounter and want to do with wasm. 
- lots of quality-of-life features
  - Easy to load into the web environment (just like a regular library / package / module, however you wanna call it) 
  - Exported `d.ts` files to assist autocomplete, and compile-time type checking with TypeScript. 
  - Automatically spits out the files needed for `npm` integration.
- Powerful bindings: automatically converts rust ` vec::f32 ` in js `Float32Array` for example. 

# CON
- CGAL, GDAL, and many other powerful libraries are absent in rust ( without bindings ), and know no valid alternatives.


# full rust + WebAssembly installation
_taken from the [game of life demo](https://rustwasm.github.io/book/game-of-life/setup.html). I extracted the steps needed for windows subsystems for linux (wsl)_

1. Download Rust: `curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh`
2. Download wasm-pack: ` curl https://rustwasm.github.io/wasm-pack/installer/init.sh -sSf | sh `
3. Get cargo-generate: `cargo install cargo-generate`
4. get npm 
5. get the template: `cargo generate --git https://github.com/rustwasm/wasm-pack-template`



----------

The original readme: 

----------

<div align="center">

  <h1><code>wasm-pack-template</code></h1>

  <strong>A template for kick starting a Rust and WebAssembly project using <a href="https://github.com/rustwasm/wasm-pack">wasm-pack</a>.</strong>

  <p>
    <a href="https://travis-ci.org/rustwasm/wasm-pack-template"><img src="https://img.shields.io/travis/rustwasm/wasm-pack-template.svg?style=flat-square" alt="Build Status" /></a>
  </p>

  <h3>
    <a href="https://rustwasm.github.io/docs/wasm-pack/tutorials/npm-browser-packages/index.html">Tutorial</a>
    <span> | </span>
    <a href="https://discordapp.com/channels/442252698964721669/443151097398296587">Chat</a>
  </h3>

  <sub>Built with 🦀🕸 by <a href="https://rustwasm.github.io/">The Rust and WebAssembly Working Group</a></sub>
</div>

## About

[**📚 Read this template tutorial! 📚**][template-docs]

This template is designed for compiling Rust libraries into WebAssembly and
publishing the resulting package to NPM.

Be sure to check out [other `wasm-pack` tutorials online][tutorials] for other
templates and usages of `wasm-pack`.

[tutorials]: https://rustwasm.github.io/docs/wasm-pack/tutorials/index.html
[template-docs]: https://rustwasm.github.io/docs/wasm-pack/tutorials/npm-browser-packages/index.html

## 🚴 Usage

### 🐑 Use `cargo generate` to Clone this Template

[Learn more about `cargo generate` here.](https://github.com/ashleygwilliams/cargo-generate)

```
cargo generate --git https://github.com/rustwasm/wasm-pack-template.git --name my-project
cd my-project
```

### 🛠️ Build with `wasm-pack build`

```
wasm-pack build
```
[JF]: DONT FORGET TO RUN `cd www && npm run build`, and then serve not `/www` but `/www/dist` ...

### 🔬 Test in Headless Browsers with `wasm-pack test`

```
wasm-pack test --headless --firefox
```

### 🎁 Publish to NPM with `wasm-pack publish`

```
wasm-pack publish
```

## 🔋 Batteries Included

* [`wasm-bindgen`](https://github.com/rustwasm/wasm-bindgen) for communicating
  between WebAssembly and JavaScript.
* [`console_error_panic_hook`](https://github.com/rustwasm/console_error_panic_hook)
  for logging panic messages to the developer console.
* [`wee_alloc`](https://github.com/rustwasm/wee_alloc), an allocator optimized
  for small code size.


