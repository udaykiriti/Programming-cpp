#![no_std]
#![no_main]

use core::panic::PanicInfo;

/// VGA text buffer is at 0xb8000
const VGA_BUFFER: *mut u8 = 0xb8000 as *mut u8;

/// Kernel entry point called from bootloader (we want symbol _start)
#[no_mangle]
pub extern "C" fn _start() -> ! {
    let msg = b"Hello qt from Rust kernel!";
    unsafe {
        // write characters to VGA text buffer (each char is 2 bytes: char, attribute)
        for (i, &b) in msg.iter().enumerate() {
            let offset = i * 2;
            VGA_BUFFER.add(offset).write_volatile(b);
            VGA_BUFFER.add(offset + 1).write_volatile(0x0f); // white on black
        }
    }

    loop {
        // halt CPU to be nice
        unsafe { core::arch::x86::_halt(); }
    }
}

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}
