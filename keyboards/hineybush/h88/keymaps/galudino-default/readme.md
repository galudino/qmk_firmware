# `galudino-default` keymap for Hineybush H88 TKL PCB

## Layout notes

- Can be used for WK or WKL layouts
- Left side R0 is macOS-centric, right side R0 is Windows-centric
- macOS recognizes this keyboard as an Apple keyboard - function row and Apple Fn key works
- Insert key is `KC_APFN` (Apple Fn key)
- Caps lock key is `LT(KM_FUNC, KC_ESC)`
  - This means that holding down Caps Lock momentarily activates the `KM_FUNC` layer (until you let go of the key)
  - Tapping Caps Lock invokes `KC_ESC` (Escape)
- There are three layers:
  - `KM_MAIN`
    - Primary layer
  - `KM_FUNC`
    - Function layer
      - Activated by holding down Caps Lock, or Fn key (to the right of 1.75u Right Shift)
      - Number row turns into F1-F12
      - Caps Lock in this layer is actually Caps lock (`KC_CAPS`)
      - U, I, O are Insert, Home, Page Up
      - N, M, , are Delete, End, Page Down
      - P, [, ] are Print Screen, Scroll Lock, and Pause
      - W, A, S, D are Up, Left, Down, Right
      - H, J, K, L are Left, Up, Down, Right
      - Holding down Space momentarily activates the `KM_SETTINGS` layer (until you let go of the key)
    - `KM_SETTINGS`
      - Activated by holding down `KM_FUNC` + Space
      - N toggles N-key rollover
      - Left Control toggles swapping Left Control and Left GUI
      - F13 invokes `RESET`
