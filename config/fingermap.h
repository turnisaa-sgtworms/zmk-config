#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/pointing.h>
#include <dt-bindings/zmk/outputs.h>

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
		sl { 							release-after-ms = < 1500 >; 																					};
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
		sk: sticky_key { release-after-ms = <750>; quick-release; lazy; /delete-property/ ignore-modifiers; 											};
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
			#define 0t0 	&kp TAB
			#define 0t1 	&kp V
			#define 0t2 	&kp Y
			#define 0t3 	&oamt 0 O
			#define 0t4 	&uemt 0 U
			#define 0t5 	&zemt Z 0
		// home row
			#define 0h0 	&amt LC(DEL) DEL
			#define 0h1 	&hml LSHIFT C
			#define 0h2 	&hml LALT I
			#define 0h3 	&hml LGUI A
			#define 0h4 	&hml LCTRL E
			#define 0h5 	&qumt Q 0
		// bottom row
			#define 0b0 	&amt LC(BSPC) BSPC
			#define 0b1 	&kp LSHIFT
			#define 0b2 	&mage_j
			#define 0b3 	&kp X
			#define 0b4 	&mage_rep
			#define 0b5 	&none
	
	// right hand
		// top row
			#define 0t6 	&kp P
			#define 0t7 	&kp D
			#define 0t8 	&kp L
			#define 0t9 	&kp F
			#define 0t10 	&kp B
			#define 0t11 	&kp ESC
		// home row
			#define 0h6 	&kp W
			#define 0h7 	&hmr RCTRL T
			#define 0h8 	&hmr RGUI H
			#define 0h9 	&hmr RALT S
			#define 0h10	&hmr RSHIFT N
			#define 0h11	&amt RC(BSPC) BSPC
		// bottom row
			#define 0b6 	&none
			#define 0b7 	&mage_k
			#define 0b8 	&kp M
			#define 0b9 	&kp G
			#define 0b10	&kp RSHIFT
			#define 0b11	&amt RC(DEL) DEL

	// thumbfan
		// 
			#define 0thlN 	&none
			#define 0thlH 	&lt 1 R
			#define 0thlF	&none
			
			#define 0thrF 	&none
			#define	0thrH	&lt 2 SPACE
			#define 0thrN	&none

// layer 1 - symbols
	// left hand
		// top row
			#define 1t0 	&kp TAB
			#define 1t1 	&kp V
			#define 1t2 	&kp Y
			#define 1t3 	&oamt 0 O
			#define 1t4 	&uemt 0 U
			#define 1t5 	&zemt Z 0
		// home row
			#define 1h0 	&amt LC(DEL) DEL
			#define 1h1 	&hml LSHIFT C
			#define 1h2 	&hml LALT I
			#define 1h3 	&hml LGUI A
			#define 1h4 	&hml LCTRL E
			#define 1h5 	&qumt Q 0
		// bottom row
			#define 1b0 	&amt LC(BSPC) BSPC
			#define 1b1 	&kp LSHIFT
			#define 1b2 	&mage_j
			#define 1b3 	&kp X
			#define 1b4 	&mage_rep
			#define 1b5 	&none
	
	// right hand
		// top row
			#define 1t6 	&kp P
			#define 1t7 	&kp D
			#define 1t8 	&kp L
			#define 1t9 	&kp F
			#define 1t10 	&kp B
			#define 1t11 	&kp ESC
		// home row
			#define 1h6 	&kp W
			#define 1h7 	&hmr RCTRL T
			#define 1h8 	&hmr RGUI H
			#define 1h9 	&hmr RALT S
			#define 1h10	&hmr RSHIFT N
			#define 1h11	&amt RC(BSPC) BSPC
		// bottom row
			#define 1b6 	&none
			#define 1b7 	&mage_k
			#define 1b8 	&kp M
			#define 1b9 	&kp G
			#define 1b10	&kp RSHIFT
			#define 1b11	&amt RC(DEL) DEL

	// thumbfan
		// 
			#define 1thlN 	&none
			#define 1thlH 	&lt 1 R
			#define 1thlF	&none
			
			#define 1thrF 	&none
			#define	1thrH	&lt 2 SPACE
			#define 1thrN	&none
