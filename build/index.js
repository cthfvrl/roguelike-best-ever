"use strict";
var term = require('terminal-kit').terminal;
var stdin = process.stdin;
var sleep = require('thread-sleep');
stdin.setRawMode(true);
stdin.resume();
var UP = 65;
var DOWN = 66;
var RIGHT = 67;
var LEFT = 68;
var SPACE = 32;
var QUIT = 113;
var lastEvent = SPACE;
var width = 300;
var height = 200;
term.clear();
var defaultMap = [];
for (var i = 1; i <= height; i++) {
    for (var j = 1; j <= width; j++) {
        if (i == 1 || i == height || j == 1 || j == width)
            defaultMap.push(true);
        else
            defaultMap.push(false);
    }
}
var SnapData = /** @class */ (function () {
    function SnapData(x, y, symbol) {
        this.x = x;
        this.y = y;
        this.symbol = symbol;
    }
    return SnapData;
}());
var World = /** @class */ (function () {
    function World() {
        this._player = new Player(this);
        this._map = new GameMap(defaultMap);
        this._mapRendered = false;
    }
    World.prototype.tick = function () {
        this._player.tick();
    };
    World.prototype.snap = function () {
        this.snapData(this._player.snap());
        if (!this._mapRendered) {
            this.snapData(this._map.snap());
            this._mapRendered = true;
        }
    };
    World.prototype.snapData = function (data) {
        data.forEach(function (value) {
            term.moveTo(value.x, value.y);
            term.red(value.symbol);
        });
    };
    World.prototype.canMoveTo = function (x, y) {
        return !defaultMap[y * height + x];
    };
    return World;
}());
var GameMap = /** @class */ (function () {
    function GameMap(mapData) {
        this._symbol = "W";
        this._mapData = mapData;
    }
    GameMap.prototype.snap = function () {
        var result = [];
        for (var i = 1; i <= height; i++) {
            for (var j = 1; j <= width; j++) {
                var isWall = this._mapData[(i - 1) * width + j - 1];
                if (isWall) {
                    result.push(new SnapData(i, j, this._symbol));
                }
            }
        }
        return result;
    };
    return GameMap;
}());
var Player = /** @class */ (function () {
    function Player(world) {
        this._x = 2;
        this._y = 2;
        this._symbol = "*";
        this._prevX = 0;
        this._prevY = 0;
        this._world = world;
    }
    Player.prototype.tick = function () {
        this._prevX = this._x;
        this._prevY = this._y;
        switch (lastEvent) {
            case UP:
                if (this._y - 1 >= 1)
                    this._y--;
                break;
            case DOWN:
                if (this._y + 1 <= height)
                    this._y++;
                break;
            case LEFT:
                if (this._x - 1 >= 1)
                    this._x--;
                break;
            case RIGHT:
                if (this._x + 1 <= width)
                    this._x++;
                break;
        }
        if (!world.canMoveTo(this._x, this._y)) {
            this._x = this._prevX;
            this._y = this._prevY;
        }
    };
    Player.prototype.snap = function () {
        if (this._prevX == 0 || this._prevY == 0)
            return [new SnapData(this._x, this._y, this._symbol)];
        var toRet = [new SnapData(this._prevX, this._prevY, " "), new SnapData(this._x, this._y, this._symbol)];
        return toRet;
    };
    return Player;
}());
var world = new World();
stdin.on('data', function (key) {
    var step = false;
    if (key.length == 3) {
        if (key[2] >= UP && key[2] <= LEFT) {
            lastEvent = key[2];
            step = true;
        }
    }
    else if (key.length == 1 && key[0] == SPACE) {
        lastEvent = SPACE;
        step = true;
    }
    if (key[0] == QUIT)
        process.exit();
    if (!step)
        return;
    world.tick();
    world.snap();
});
