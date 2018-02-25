class AllOne {
    constructor() {
        this.data = {};
        this.value = {};
    }

    addValueForKey(value, key) {
        if (!(value in this.value)) {
            this.value[value] = {};
        }
        this.value[value][key] = true;
    }

    removeValueForKey(value, key) {
        delete this.value[value][key];
        if (Object.keys(this.value[value]).length === 0) {
            delete this.value[value];
        }
    }

    inc(key) {
        if (key in this.data) {
            this.removeValueForKey(this.data[key], key);
            this.data[key] += 1;
            this.addValueForKey(this.data[key], key);
        } else {
            this.data[key] = 1;
            this.addValueForKey(this.data[key], key);
        }
    }

    dec(key) {
        if (key in this.data) {
            this.removeValueForKey(this.data[key], key);
            this.data[key] -= 1;
            if (this.data[key] === 0) {
                delete this.data[key];
            } else {
                this.addValueForKey(this.data[key], key);
            }
        } 
    }

    getMaxKey() {
        let valueKeys = Object.keys(this.value);
        let len = valueKeys.length;
        if (len === 0) {
            return "";
        }
        let maxValue = valueKeys[len - 1];
        let node = this.value[maxValue];
        let keys = Object.keys(node);
        return keys[0];
    }

    getMinKey() {
        let valueKeys = Object.keys(this.value);
        let len = valueKeys.length;
        if (len === 0) {
            return "";
        }
        let maxValue = valueKeys[0];
        let node = this.value[maxValue];
        let keys = Object.keys(node);
        return keys[0];
    }

}

