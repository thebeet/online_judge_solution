function memoize(fn) {
    const EOP = Symbol('end of params');
    const hash = new Map([]);
    return function(...params) {
        let c = hash;
        for (const p of params) {
            if (!c.has(p)) {
                c.set(p, new Map([]));
            }
            c = c.get(p);
        }
        if (!c.has(EOP)) {
            c.set(EOP, fn(...params));
        }
        return c.get(EOP);
    }
}
