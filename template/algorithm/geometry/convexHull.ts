const EPSILON = 1e-9;

class Vector2 {
    x: number;
    y: number;

    constructor(x: number = 0, y: number = 0) {
        this.x = x;
        this.y = y;
    }

    copy(source: Vector2): Vector2 {
        this.x = source.x;
        this.y = source.y;
        return this;
    }

    add(v: Vector2) {
        this.x += v.x;
        this.y += v.y;
        return this;
    }

    sub(v: Vector2) {
        this.x -= v.x;
        this.y -= v.y;
        return this;
    }

    dot(v: Vector2): number {
		return this.x * v.x + this.y * v.y;
	}

    cross(v: Vector2): number {
		return this.x * v.y - this.y * v.x;
	}
}

// Andrew Algorithm 
export const convexHull2D = (p: Vector2[]): Vector2[] => {
    const n = p.length;
    if (n <= 2) {
        return p;
    }
    const points = [...p];
    points.sort((p1, p2) => {
        if (p1.x === p2.x) {
            return p1.y - p2.y;
        }
        return p1.x - p2.x;
    });
    const stack: number[] = [];
    const used = new Array<boolean>(n).fill(false);
    stack.push(0);

    const _v1 = new Vector2();
    const _v2 = new Vector2();
    for (let i = 1; i < n; ++i) {
        while (stack.length > 1) {
            _v1.copy(points[stack[stack.length - 1]]).sub(points[stack[stack.length - 2]]);
            _v2.copy(points[i]).sub(points[stack[stack.length - 1]]);
            if (_v1.cross(_v2) > EPSILON) {
                break;
            }
            used[stack[stack.length - 1]] = false;
            stack.pop();
        }
        used[i] = true;
        stack.push(i);
    }

    const stackBar = stack.length;
    for (let i = n - 1; i >= 0; --i) {
        if (!used[i]) {
            while (stack.length > stackBar) {
                _v1.copy(points[stack[stack.length - 1]]).sub(points[stack[stack.length - 2]]);
                _v2.copy(points[i]).sub(points[stack[stack.length - 1]]);
                if (_v1.cross(_v2) > EPSILON) {
                    break;
                }
                used[stack[stack.length - 1]] = false;
                stack.pop();
            }
            used[i] = true;
            stack.push(i);
        }
    }
    return stack.map(index => points[index]);
};