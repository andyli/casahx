package test;

import flash.events.Event;
import flash.events.KeyboardEvent;

import org.casalib.events.KeyComboEvent;
import org.casalib.ui.Key;
import org.casalib.ui.KeyCombo;
import org.casalib.util.StageReference;

class TestUi extends flash.display.Sprite {
	public var key:Key;
	public var asdfCombo:KeyCombo;
    public var casaCombo:KeyCombo;

	public function new() {
		super();
		
		StageReference.setStage(neash.Lib.current.stage);
		
		key = Key.getInstance();
		
		asdfCombo = new KeyCombo([65, 83, 68, 70]);
		key.addKeyCombo(asdfCombo);
		
		casaCombo = new KeyCombo([67, 65, 83, 65]);
		key.addKeyCombo(casaCombo);
		
		key.addEventListener(KeyComboEvent.DOWN, this.onComboDown);
        key.addEventListener(KeyComboEvent.RELEASE, this.onComboRelease);
    		key.addEventListener(KeyComboEvent.SEQUENCE, this.onComboTyped);
        key.addEventListener(KeyboardEvent.KEY_DOWN, this.onKeyPressed);
        key.addEventListener(KeyboardEvent.KEY_UP, this.onKeyReleased);
        
        trace("Try pressing 'a'+'s'+'d'+'f' or type 'casa'.");
	}
	
	static public function main():Void {
		neash.Lib.Init("Test UI", 400, 300);
		flash.Lib.current.addChild(new TestUi());
		neash.Lib.Run();
	}
	
	public function onComboDown(e:KeyComboEvent):Void {
            if (this.asdfCombo.equals(e.keyCombo)) {
                trace("User is holding down keys a-s-d-f.");
            }
        }

    public function onComboRelease(e:KeyComboEvent):Void {
        if (this.asdfCombo.equals(e.keyCombo)) {
            trace("User no longer holding down keys a-s-d-f.");
        }
    }

    public function onComboTyped(e:KeyComboEvent):Void {
        if (this.casaCombo.equals(e.keyCombo)) {
            trace("User typed casa.");
        }
    }

    public function onKeyPressed(e:KeyboardEvent):Void {
        trace("User pressed key with code: " + e.keyCode + ".");
    }

    public function onKeyReleased(e:KeyboardEvent):Void {
        trace("User released key with code: " + e.keyCode + ".");
    }
}
