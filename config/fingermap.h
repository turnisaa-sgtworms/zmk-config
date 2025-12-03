#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/pointing.h>
#include <dt-bindings/zmk/outputs.h>
#include <behaviors/num_word.dtsi>
#include <behaviors/unicode.dtsi>

#define ZMK_POINTING_DEFAULT_MOVE_VAL 1200  // default: 600
#define AS(keycode) &as LS(keycode) keycode
#define RAS(keycode) &as keycode LS(keycode)

/ { macros {	par: par 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LPAR &kp RPAR &kp LEFT>;			};
				brc: brc 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LBRC &kp RBRC &kp LEFT>; 			};
				bkt: bkt 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LBKT &kp RBKT &kp LEFT>; 			};
				quo: quo 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LS(APOS) &kp LS(APOS) &kp LEFT>; 	};
				gra: gra 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp GRAVE &kp GRAVE &kp LEFT>; 		};
				abt: abt 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LS(COMMA) &kp LS(DOT) &kp LEFT>; 	};
				bar: bar 	{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp LS(BSLH) &kp LS(BSLH) &kp LEFT>; 	};
        	
				qu: qu 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp Q &kp U>; 							};
				ze: ze 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp Z &kp E>; 							};
				oa: oa 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp O &kp A>; 							};
				ue: ue 		{ wait-ms = <10>; tap-ms = <10>; compatible = "zmk,behavior-macro"; #binding-cells = <0>; bindings = <&macro_tap &kp U &kp E>; 							}; };

	behaviors {
		hml: home_row_mod_l { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; require-prior-idle-ms = <200>; 
   			tapping-term-ms = <275>; quick-tap-ms = <175>; hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; hold-trigger-on-release; 			};
        hmr: home_row_mod_r { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; require-prior-idle-ms = <200>;
			tapping-term-ms = <200>; quick-tap-ms = <175>; hold-trigger-key-positions = <>; bindings = <&kp>, <&kp>; hold-trigger-on-release; 			};
		
        num_word: num_word { 			#binding-cells = <1>; compatible = "zmk,behavior-auto-layer"; 
										continue-list = < BSPC DEL DOT COMMA PLUS MINUS STAR FSLH EQUAL >; ignore-numbers;								};
		amt: a_mod_tap { 				compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; 
										tapping-term-ms = <200>; bindings = <&kp>, <&kp>; display-name = "a-Mod-Tap"; 									};
		mage_rep: mage_rep { 			compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&key_repeat>;
											akt_yi { trigger-keys = <Y>; max-prior-idle-ms = <300>; bindings = <&kp I>; };
            								akt_ji { trigger-keys = <J>; max-prior-idle-ms = <300>; bindings = <&kp I>; }; 								};
		mage_k: mage_k { 				compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp K>;
											akt_tw { trigger-keys = <T>; max-prior-idle-ms = <300>; bindings = <&kp W>; };
											akt_gs { trigger-keys = <G>; max-prior-idle-ms = <300>; bindings = <&kp S>; }; 								};
		mage_j: mage_j { 				compatible = "zmk,behavior-adaptive-key"; #binding-cells = <0>; bindings = <&kp J>;
											akt_ue { trigger-keys = <U>; max-prior-idle-ms = <300>; bindings = <&kp E>; }; 								};
		cmt: caps_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "balanced"; tapping-term-ms = <200>; 
			bindings = <&kp>, <&caps_word>; display-name = "Caps-Tap"; 																					};
		uc: unicode { default-mode = <UC_MODE_WIN_COMPOSE>;																								};
		sl: sticky_layer { release-after-ms = < 1500 >; 																								};
		sk: sticky_key { release-after-ms = <750>; quick-release; 																						};
		mt: mod_tap { tapping-term-ms = <200>; 																											};
		quomt: quo_mod_tap { compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>; 
			bindings = <&quo>, <&kp>; display-name = "quo Mod-Tap"; 																					};
		parmt: par_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&gra>, <&par>; display-name = "par Mod-Tap"; 																					};
		brcmt: brc_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
			bindings = <&abt>, <&brc>; display-name = "brc Mod-Tap"; 																					};
		bktmt: bkt_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&bar>, <&bkt>; display-name = "bkt Mod-Tap"; 																					};
		gramt: gra_mod_tap { compatible = "zmk,behavior-hold-tap";  #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&gra>, <&kp>; display-name = "gra Mod-Tap"; 																					};
		abtmt: abt_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&abt>, <&kp>; display-name = "abt Mod-Tap"; 																					};
		barmt: bar_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>; 
			bindings = <&bar>, <&kp>; display-name = "bar Mod-Tap"; 																					};
		qumt: qu_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&kp>, <&qu>; display-name = "qu Mod-Tap"; 																						};
		zemt: ze_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
        	bindings = <&kp>, <&ze>; display-name = "ze Mod-Tap"; 																						};
		oamt: oa_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&oa>, <&kp>; display-name = "oa Mod-Tap"; 																						};
		uemt: ue_mod_tap { compatible = "zmk,behavior-hold-tap"; #binding-cells = <2>; flavor = "tap-preferred"; tapping-term-ms = <150>;
            bindings = <&ue>, <&kp>;  display-name = "ue Mod-Tap"; 																						}; }; };


//
// t0  t1  t2  t3  t4  t5  t6  t7  t8  t9  t10  t11
// h0 *h1**h2**h3**h4* h5  h6 *h7**h8**h9**h10* h11
// b0  b1  b2  b3  b4  b5  b6  b7  b8  b9  b10  b11
//       thlN *thlH* thlF  thrF *thrH* thrL
//

// layer 0 - default
	// left hand
		// top row
			#define _0t0 	&kp TAB
			#define _0t1 	&kp V
			#define _0t2 	&kp Y
			#define _0t3 	&oamt 0 O
			#define _0t4 	&uemt 0 U
			#define _0t5 	&zemt Z 0
		// home row
			#define _0h0 	&amt LC(DEL) DEL
			#define _0h1 	&hml LALT C
			#define _0h2 	&hml LCTRL I
			#define _0h3 	&hml LGUI A
			#define _0h4 	&hml LSHIFT E
			#define _0h5 	&qumt Q 0
		// bottom row
			#define _0b0 	&amt LC(BSPC) BSPC
			#define _0b1 	&kp LSHIFT
			#define _0b2 	&mage_j
			#define _0b3 	&kp X
			#define _0b4 	&mage_rep
			#define _0b5 	&none
	
	// right hand
		// top row
			#define _0t6 	&kp P
			#define _0t7 	&kp D
			#define _0t8 	&kp L
			#define _0t9 	&kp F
			#define _0t10 	&kp B
			#define _0t11 	&kp ESC
		// home row
			#define _0h6 	&kp W
			#define _0h7 	&hmr RSHIFT T
			#define _0h8 	&hmr RGUI H
			#define _0h9 	&hmr RCTRL S
			#define _0h10	&hmr RALT N
			#define _0h11	&amt RC(BSPC) BSPC
		// bottom row
			#define _0b6 	&none
			#define _0b7 	&mage_k
			#define _0b8 	&kp M
			#define _0b9 	&kp G
			#define _0b10	&kp RSHIFT
			#define _0b11	&amt RC(DEL) DEL

	// thumbfan
		// 
			#define _0thlN 	&none
			#define _0thlH 	&lt 1 R
			#define _0thlF	&none
			
			#define _0thrF 	&none
			#define	_0thrH	&lt 2 SPACE
			#define _0thrN	&none

// layer 1 - symbols
	// left hand
		// top row
			#define _1t0 	&kp TAB
			#define _1t1 	&none
			#define _1t2 	&amt LS(N3) 	LS(N5)
			#define _1t3 	&amt LS(N6) 	LS(N2)
			#define _1t4 	&amt LS(EQUAL) 	MINUS
			#define _1t5 	&amt PIPE 		GRAVE
		// home row
			#define _1h0 	&amt LC(DEL) 	DEL
			#define _1h1 	&amt LS(MINUS)	N3
			#define _1h2 	&amt LS(N7) 	N2
			#define _1h3 	&amt EQUAL 		N1
			#define _1h4 	&amt SEMI 		N0
			#define _1h5 	&amt LS(GRAVE) 	N4
		// bottom row
			#define _1b0 	&amt LC(BSPC) 	BSPC
			#define _1b1 	&kp LSHIFT
			#define _1b2 	&amt LBKT 		LS(COMMA)
			#define _1b3 	&amt LS(LBKT) 	DQT
			#define _1b4 	&amt LPAR 		COMMA
			#define _1b5 	&none
	
	// right hand
		// top row
			#define _1t6 	&amt BSLH 		FSLH
			#define _1t7 	&parmt 0 		0 
			#define _1t8 	&brcmt 0 		0
			#define _1t9 	&bktmt 0 		0
			#define _1t10 	&none
			#define _1t11 	&kp ESC
		// home row
			#define _1h6 	&amt LS(N4) 	N9
			#define _1h7 	&amt COLON 		N5
			#define _1h8 	&amt LS(N8) 	N6
			#define _1h9 	&amt LS(N1) 	N7
			#define _1h10	&amt LS(FSLH) 	N8
			#define _1h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _1b6 	&none
			#define _1b7 	&amt RPAR 		DOT
			#define _1b8 	&amt LS(RBKT) 	APOS
			#define _1b9 	&amt RBKT 		LS(DOT)
			#define _1b10	&kp RSHIFT
			#define _1b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _1thlN 	&none
			#define _1thlH 	&none
			#define _1thlF	&none
			
			#define _1thrF 	&none
			#define	_1thrH	&kp SPACE
			#define _1thrN	&none

// layer 2 - shortcuts
	// left hand
		// top row
			#define _2t0 	&kp TAB
			#define _2t1 	&none
			#define _2t2 	&amt LC(LS(W)) 	LC(W)
			#define _2t3 	&amt LC(LS(R)) 	LC(R)
			#define _2t4 	&amt LC(LS(T)) 	LC(T)
			#define _2t5 	&amt LC(LS(Y)) 	LC(Y)
		// home row
			#define _2h0 	&amt LC(DEL) 	DEL
			#define _2h1 	&amt LC(LS(A)) 	LC(A)
			#define _2h2 	&amt LC(LS(X)) 	LC(X)
			#define _2h3 	&amt LC(LS(C)) 	LC(C)
			#define _2h4 	&amt LC(LS(V)) 	LC(V)
			#define _2h5 	&amt LC(LS(Z)) 	LC(Z)
		// bottom row
			#define _2b0 	&amt LC(BSPC) 	BSPC
			#define _2b1 	&kp LSHIFT
			#define _2b2 	&amt LC(LS(S)) 	LC(S)
			#define _2b3 	&amt LC(LS(D)) 	LC(D)
			#define _2b4 	&amt LC(LS(F)) 	LC(F)
			#define _2b5 	&none
	
	// right hand
		// top row
			#define _2t6 	&kp C_PP
			#define _2t7 	&kp C_PREV
			#define _2t8 	&kp C_NEXT
			#define _2t9 	&kp PGUP
			#define _2t10 	&none
			#define _2t11 	&kp ESC
		// home row
			#define _2h6 	&kp C_MUTE 		
			#define _2h7 	&amt LC(LEFT) 	LEFT	
			#define _2h8 	&amt LC(UP) 	UP 			
			#define _2h9 	&amt LC(DOWN) 	DOWN		
			#define _2h10	&amt LC(RIGHT) 	RIGHT
			#define _2h11	&amt RC(BSPC) 	BSPC 
		// bottom row
			#define _2b6 	&none
			#define _2b7 	&kp HOME   		
			#define _2b8 	&kp END 	 		
			#define _2b9 	&kp PGDN
			#define _2b10	&kp RSHIFT
			#define _2b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _2thlN 	&none
			#define _2thlH 	&kp PSCRN
			#define _2thlF	&none
			
			#define _2thrF 	&none
			#define	_2thrH	&none
			#define _2thrN	&none

// layer 3 - f keys
	// left hand
		// top row
			#define _3t0 	&kp TAB
			#define _3t1 	&none
			#define _3t2 	&none
			#define _3t3 	&none
			#define _3t4 	&none
			#define _3t5 	&none
		// home row
			#define _3h0 	&amt LC(DEL) 	DEL
			#define _3h1 	&kp F3
			#define _3h2 	&kp F2
			#define _3h3 	&kp F1
			#define _3h4 	&kp F4
			#define _3h5 	&kp F10
		// bottom row
			#define _3b0 	&amt LC(BSPC) 	BSPC
			#define _3b1 	&kp LSHIFT
			#define _3b2 	&none
			#define _3b3 	&none
			#define _3b4 	&none
			#define _3b5 	&none
	
	// right hand
		// top row
			#define _3t6 	&none
			#define _3t7 	&none
			#define _3t8 	&none
			#define _3t9 	&none
			#define _3t10 	&none
			#define _3t11 	&kp ESC
		// home row
			#define _3h6 	&kp F9
			#define _3h7 	&kp F5
			#define _3h8 	&kp F6
			#define _3h9 	&kp F7
			#define _3h10	&kp F8
			#define _3h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _3b6 	&none
			#define _3b7 	&none
			#define _3b8 	&none
			#define _3b9 	&none
			#define _3b10	&kp RSHIFT
			#define _3b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _3thlN 	&none
			#define _3thlH 	&kp F11
			#define _3thlF	&none
			
			#define _3thrF 	&none
			#define	_3thrH	&kp F12
			#define _3thrN	&none

// layer 4 - qwer
	// left hand
		// top row
			#define _4t0 	&kp TAB
			#define _4t1 	&none
			#define _4t2 	&kp N1
			#define _4t3 	&kp N2
			#define _4t4 	&kp N3
			#define _4t5 	&kp N4
		// home row
			#define _4h0 	&amt LC(DEL) 	DEL
			#define _4h1 	&kp Q
			#define _4h2 	&kp W
			#define _4h3 	&kp E
			#define _4h4 	&kp R
			#define _4h5 	&mt B G
		// bottom row
			#define _4b0 	&amt LC(BSPC) 	BSPC
			#define _4b1 	&kp LSHIFT
			#define _4b2 	&mt LALT X
			#define _4b3 	&kp D
			#define _4b4 	&kp F
			#define _4b5 	&none
	
	// right hand
		// top row
			#define _4t6 	&kp C_PP
			#define _4t7 	&kp C_PREV
			#define _4t8 	&kp C_NEXT
			#define _4t9 	&kp F7
			#define _4t10 	&none
			#define _4t11 	&kp ESC
		// home row
			#define _4h6 	&kp C_MUTE
			#define _4h7 	&kp F2
			#define _4h8 	&kp F3
			#define _4h9 	&kp F5
			#define _4h10	&kp F6
			#define _4h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _4b6 	&none
			#define _4b7 	&kp C_VOL_DN
			#define _4b8 	&kp C_VOL_UP
			#define _4b9 	&kp F8
			#define _4b10	&kp RSHIFT
			#define _4b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _4thlN 	&none
			#define _4thlH 	&mt LCTRL SPACE
			#define _4thlF	&none
			
			#define _4thrF 	&none
			#define	_4thrH	&none
			#define _4thrN	&none

// layer 5 - minecraft
	// left hand
		// top row
			#define _5t0 	&kp TAB
			#define _5t1 	&none
			#define _5t2 	&kp N1
			#define _5t3 	&kp N2
			#define _5t4 	&kp N3
			#define _5t5 	&kp N4
		// home row
			#define _5h0 	&amt LC(DEL) 	DEL
			#define _5h1 	&kp LSHIFT
			#define _5h2 	&kp A
			#define _5h3 	&kp W
			#define _5h4 	&kp D
			#define _5h5 	&mt B G
		// bottom row
			#define _5b0 	&amt LC(BSPC) 	BSPC
			#define _5b1 	&kp LSHIFT
			#define _5b2 	&kp Q
			#define _5b3 	&kp S
			#define _5b4 	&kp E
			#define _5b5 	&none
	
	// right hand
		// top row
			#define _5t6 	&kp C_PP
			#define _5t7 	&kp C_PREV
			#define _5t8 	&kp C_NEXT
			#define _5t9 	&kp F7
			#define _5t10 	&none
			#define _5t11 	&kp ESC
		// home row
			#define _5h6 	&kp C_MUTE
			#define _5h7 	&kp F2
			#define _5h8 	&kp F3
			#define _5h9 	&kp F5
			#define _5h10	&kp F6
			#define _5h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _5b6 	&none
			#define _5b7 	&kp C_VOL_DN
			#define _5b8 	&kp C_VOL_UP
			#define _5b9 	&kp F8
			#define _5b10	&kp RSHIFT
			#define _5b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _5thlN 	&none
			#define _5thlH 	&kp SPACE
			#define _5thlF	&none
			
			#define _5thrF 	&none
			#define	_5thrH	&none
			#define _5thrN	&none

// layer 6 - fps
	// left hand
		// top row
			#define _6t0 	&kp TAB
			#define _6t1 	&none
			#define _6t2 	&kp Q
			#define _6t3 	&kp F
			#define _6t4 	&kp E
			#define _6t5 	&kp R
		// home row
			#define _6h0 	&amt LC(DEL) 	DEL
			#define _6h1 	&kp LSHIFT
			#define _6h2 	&kp A
			#define _6h3 	&kp W
			#define _6h4 	&kp D
			#define _6h5 	&mt B G
		// bottom row
			#define _6b0 	&amt LC(BSPC) 	BSPC
			#define _6b1 	&kp LSHIFT
			#define _6b2 	&mt Z X
			#define _6b3 	&kp S
			#define _6b4 	&mt V C
			#define _6b5 	&none
	
	// right hand
		// top row
			#define _6t6 	&kp C_PP
			#define _6t7 	&kp C_PREV
			#define _6t8 	&kp C_NEXT
			#define _6t9 	&kp F7
			#define _6t10 	&none
			#define _6t11 	&kp ESC
		// home row
			#define _6h6 	&kp C_MUTE
			#define _6h7 	&kp F2
			#define _6h8 	&kp F3
			#define _6h9 	&kp F5
			#define _6h10	&kp F6
			#define _6h11	&amt RC(BSPC) 	BSPC
		// bottom row
			#define _6b6 	&none
			#define _6b7 	&kp C_VOL_DN
			#define _6b8 	&kp C_VOL_UP
			#define _6b9 	&kp F8
			#define _6b10	&kp RSHIFT
			#define _6b11	&amt RC(DEL) 	DEL

	// thumbfan
		// 
			#define _6thlN 	&none
			#define _6thlH 	&kp SPACE
			#define _6thlF	&none
			
			#define _6thrF 	&none
			#define	_6thrH	&none
			#define _6thrN	&none
