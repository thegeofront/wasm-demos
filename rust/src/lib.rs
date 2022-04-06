mod utils;

use wasm_bindgen::prelude::*;

// When the `wee_alloc` feature is enabled, use `wee_alloc` as the global
// allocator.
#[cfg(feature = "wee_alloc")]
#[global_allocator]
static ALLOC: wee_alloc::WeeAlloc = wee_alloc::WeeAlloc::INIT;

#[wasm_bindgen]
extern {
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet() {
    alert("Hello, hello-rust-wasm!");
}

#[wasm_bindgen]
pub fn multi_lerp(a: f64, b: f64, vector: Vec<f64>) -> Vec<f64> {
    let mut res: Vec<f64> = Vec::new();
    for i in 0..vector.len() {
        res.push(lerp(a, b, vector[i]));
    }
    return res;
}

#[wasm_bindgen]
pub fn lerp(a: f64, b: f64, t: f64) -> f64 {
    return (1.0 - t) * a + t * b;
}

#[wasm_bindgen]
pub fn add(a: f32, b: f32) -> f32 {
    a + b
}

#[wasm_bindgen]
pub fn substract(a: f32, b: f32) -> f32 {
    a - b
}
