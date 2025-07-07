#define AS(keycode) &as LS(keycode) keycode

/ {
	macros {
        	qu: qu {
            		compatible = "zmk,behavior-macro";
            		#binding-cells = <0>;
            		bindings
                	= <&macro_tap &kp Q &kp U>
                	;
        	};
		lol: lol {
            		compatible = "zmk,behavior-macro";
            		#binding-cells = <0>;
            		bindings
                	= <&macro_tap &kp L &kp O &kp L>
                	;
        	};
		lmao: lmao {
            		compatible = "zmk,behavior-macro";
            		#binding-cells = <0>;
            		bindings
                	= <&macro_tap &kp L &kp M &kp A &kp O>
                	;
        	};
    	};
	behaviors {
		td0: tap_dance_parentheseseseses {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp LPAR>, <&kp RPAR>;
		};
		td1: tap_dance_braces {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp LBRC>,<&kp RBRC>;
		};
		td2: tap_dance_brackets {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp LBKT>,<&kp RBKT>;
		};
		td3: tap_dance_tabesc {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp TAB>,<&kp ESC>;
		};
		td4: tap_dance_cx {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp C>,<&kp X>;
		};
		td5: tap_dance_fg {
			compatible = "zmk,behavior-tap-dance";
			#binding-cells = <0>;
			tapping-term-ms = <225>;
			bindings = <&kp F>,<&kp G>;
		};
		hml: home_row_mod_left {
            		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		flavor = "balanced";
            		require-prior-idle-ms = <100>;
            		tapping-term-ms = <250>;
            		quick-tap-ms = <175>;
            		bindings = <&kp>, <&kp>;
            		hold-trigger-on-release;
        	};
        	hmr: home_row_mod_right {
            		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		flavor = "balanced";
            		require-prior-idle-ms = <100>;
            		tapping-term-ms = <250>;
            		quick-tap-ms = <175>;
            		bindings = <&kp>, <&kp>;
            		hold-trigger-on-release;
        	};
		as: auto_shift {
            		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		tapping_term_ms = <175>;
            		quick_tap_ms = <0>;
            		flavor = "tap-preferred";
            		bindings = <&kp>, <&kp>;
        	};
		hw_soft_off: hw_soft_off {
            		compatible = "zmk,behavior-soft-off";
            		#binding-cells = <0>;
            		split-peripheral-off-on-press; // Turn peripheral off immediately for reliability
            		hold-time-ms = <1500>; // Only turn off if the key is held for 1.5 seconds or longer.
        	};
		fmt: fast_mod_tap {
        		compatible = "zmk,behavior-hold-tap";
            		#binding-cells = <2>;
            		flavor = "hold-preferred";
            		tapping-term-ms = <125>;
            		bindings = <&kp>, <&kp>;
            		display-name = "Fast Mod-Tap";
        	};
		mt: mod_tap {
            		tapping-term-ms = <200>;
        	};
	};


// layer 0 - base
	// left hand
		// top row
			#define LUO &kp TAB
			#define LUP &none
			#define LUR &kp U
			#define LUM &kp O
			#define LUI &kp G
			#define LUN &kp J
		// home row
			#define LHO &kp DEL
			#define LHP &hml LSHIFT A
			#define LHR &kp I
			#define LHM &hml LALT E
			#define LHI &hml LCTRL T
			#define LHN &kp K
		// bottom row
			#define LBO &none
			#define LBP &none
			#define LBR &none
			#define LBM &kp X
			#define LBI &kp B
			#define LBN &kp Z
	
	// right hand
		// top row
			#define RUO &none
			#define RUP &qu
			#define RUR &kp C
			#define RUM &kp Y
			#define RUI &kp M
			#define RUN &kp F
		// home row
			#define RHO &kp BSPC
			#define RHP &hmr RSHIFT H
			#define RHR &kp D
			#define RHM &hmr RALT S
			#define RHI &hmr RCTRL N
			#define RHN &kp P
		// bottom row
			#define RBO &none
			#define RBP &none
			#define RBR &none
			#define RBM &kp W
			#define RBI &kp L
			#define RBN &kp V

	// thumbfan
		// 2 keys
			#define L0 &lt 2 R
			#define R0 &lt 1 SPACE
		// 4 keys
			#define LN &lt 3 J
			#define LH &lt 2 R

			#define	RH &lt 1 SPACE
			#define RN &lt 4 Z

// layer 1 - numbers and icons
	// left hand
		// top row
			#define LUO1 &none
			#define LUP1 AS(GRAVE)
			#define LUR1 AS(N1)
			#define LUM1 AS(N2)
			#define LUI1 AS(N3)
			#define LUN1 &none
		// home row
			#define LHO1 &none
			#define LHP1 AS(N0)
			#define LHR1 AS(N4)
			#define LHM1 AS(N5)
			#define LHI1 AS(N6)
			#define LHN1 &none
		// bottom row
			#define LBO1 &none
			#define LBP1 &none
			#define LBR1 &none
			#define LBM1 AS(N7)
			#define LBI1 AS(N8)
			#define LBN1 &none
	
	// right hand
		// top row
			#define RUO1 &none
			#define RUP1 AS(GRAVE)
			#define RUR1 &td2
			#define RUM1 &td1
			#define RUI1 &td0
			#define RUN1 AS(GRAVE)
		// home row
			#define RHO1 &none
			#define RHP1 AS(SLSH)
			#define RHR1 AS(DOT)
			#define RHM1 AS(COMMA)
			#define RHI1 AS(SEMI)
			#define RHN1 AS(EQUAL)
		// bottom row
			#define RBO1 &none
			#define RBP1 AS(BSLSH)
			#define RBR1 AS(EQUAL)
			#define RBM1 AS(MINUS)
			#define RBI1 AS(APOSTROPHE)
			#define RBN1 AS(BSLSH)

	// thumbfan
		// 2 keys
			#define L1 AS(N9)
			#define R1 &none
		// 4 keys
			#define LN1 &none
			#define LH1 AS(N9)

			#define	RH1 &none
			#define RN1 &none

// layer 2 - nav/kb functions
	// left hand
		// top row
			#define LUO2 &none
			#define LUP2 &none
			#define LUR2 &studio_unlock
			#define LUM2 &bt BT_CLR_ALL
			#define LUI2 &hw_soft_off
			#define LUN2 &none
		// home row
			#define LHO2 &none
			#define LHP2 &none 
			#define LHR2 &kp HOME
			#define LHM2 &kp PGUP 
			#define LHI2 &kp END
			#define LHN2 &none
		// bottom row
			#define LBO2 &none
			#define LBP2 &none
			#define LBR2 &none
			#define LBM2 &kp PGDN
			#define LBI2 &none
			#define LBN2 &none
	
	// right hand
		// top row
			#define RUO2 &none
			#define RUP2 &none
			#define RUR2 &kp C_NEXT
			#define RUM2 &kp C_PP
			#define RUI2 &kp C_PREV
			#define RUN2 &none
		// home row
			#define RHO2 &none
			#define RHP2 &none
			#define RHR2 &kp RIGHT
			#define RHM2 &kp UP
			#define RHI2 &kp LEFT
			#define RHN2 &none
		// bottom row
			#define RBO2 &none
			#define RBP2 &none
			#define RBR2 &none
			#define RBM2 &kp DOWN
			#define RBI2 &none
			#define RBN2 &none

	// thumbfan
		// 2 keys
			#define L2 &none
			#define R2 &none
		// 4 keys
			#define LN2 &none
			#define LH2 &none

			#define	RH2 &none
			#define RN2 &none

