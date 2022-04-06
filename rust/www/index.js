import * as wasm from "hello-rust-wasm";

let log = (str) => document.body.innerText += str; 

log(`The answer is ${wasm.add(40, 2)}\n`);
log(`The halfway between -405.9 and 249983.5 is: ${wasm.lerp(-405.9, 249983.5, 0.5)}\n`);
log(`some values between 5 and 10:  ${wasm.multi_lerp(5, 10, new Float64Array([0.3, 0.4, 0.7, 0.9]))}\n`);