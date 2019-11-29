let term = require('terminal-kit').terminal
let stdin = process.stdin;
let sleep = require('thread-sleep')

stdin.setRawMode(true)
stdin.resume()

const UP = 65
const DOWN = 66
const RIGHT = 67
const LEFT = 68
const SPACE = 32
const QUIT = 113

let lastEvent = SPACE

const width = 300
const height = 200

term.clear()

let defaultMap: boolean[] = []
for(let i = 1; i <= height; i++){
    for(let j = 1; j <= width; j++){
        if(i == 1 || i == height || j == 1 || j == width)
            defaultMap.push(true)
        else defaultMap.push(false)
    }
}

class SnapData {
    x: number
    y: number
    symbol: string

    constructor(x: number, y: number, symbol: string){
        this.x = x
        this.y = y
        this.symbol = symbol
    }
}

class World {

    _player = new Player(this)
    _map = new GameMap(defaultMap)
    _mapRendered = false

    tick() {
        this._player.tick()
    }

    snap() {
        this.snapData(this._player.snap())

        if(!this._mapRendered){
            this.snapData(this._map.snap())
            this._mapRendered = true
        }
    }

    snapData(data: SnapData[]){
        data.forEach(value => {
            term.moveTo(value.x, value.y)
            term.red(value.symbol)
        })
    }

    canMoveTo(x: number, y: number): boolean {
        return !defaultMap[y * height + x]
    }
}

class GameMap {

    _mapData: boolean[]
    _symbol = "W"

    constructor(mapData: boolean[]){
        this._mapData = mapData
    }

    snap(): SnapData[] {
        let result: SnapData[] = []

        for(let i = 1; i <= height; i++){
            for(let j = 1; j <= width; j++){
                const isWall = this._mapData[(i - 1) * width + j - 1]
                if(isWall){
                    result.push(new SnapData(i, j, this._symbol))
                }
            }
        }

        return result
    }

}

class Player {
    _x: number = 2
    _y: number = 2
    _symbol: string = "*"

    _prevX: number = 0
    _prevY: number = 0

    _world: World
    constructor(world: World){
        this._world = world
    }

    tick() {
        this._prevX = this._x
        this._prevY = this._y

        switch(lastEvent){
            case UP:
                if(this._y - 1 >= 1)
                    this._y--
                break
            case DOWN:
                if(this._y + 1 <= height)
                    this._y++
                break
            case LEFT:
                if(this._x - 1 >= 1)
                    this._x--
                break
            case RIGHT:
                if(this._x + 1 <= width)
                    this._x++
                break
        }

        if(!world.canMoveTo(this._x, this._y)){
            this._x = this._prevX
            this._y = this._prevY
        }
    }

    snap(): SnapData[] {
        if(this._prevX == 0 || this._prevY == 0)
            return [new SnapData(this._x, this._y, this._symbol)]

        const toRet = [new SnapData(this._prevX, this._prevY, " "), new SnapData(this._x, this._y, this._symbol)]

        return toRet
    }
}

const world = new World()

stdin.on('data', key => {
    let step = false

    if(key.length == 3){
        if(key[2] >= UP && key[2] <= LEFT){
            lastEvent = key[2]
            step = true
        }
    } else if(key.length == 1 && key[0] == SPACE){
        lastEvent = SPACE
        step = true
    }

    if(key[0] == QUIT)
        process.exit()

    if(!step)
        return

    world.tick()
    world.snap()
})