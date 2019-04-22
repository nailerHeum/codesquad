class DengDeng {
  constructor(name) {
      this.name = name;
  }
  get age() {
      return this.shootAge(this.name);
  }
  shootAge(name) {
      return name.length;
  }
  bark(){
    console.log('개가 짖는다!')
  }
  static dengPlus(dog1, dog2){
    return dog1.age + dog2.age
  }
}
var mongmong = new DengDeng('멍멍이')
var barkbark = new DengDeng('막시무스')

class Jindodog extends DengDeng {
  constructor(name, barkSound){
    super()
    this.name = name
    this.barkSound = barkSound
  }
  bark(){
    super.bark()
    console.log(this.barkSound)
  }
}
var jindol = new Jindodog('진돌이', '월월!')

console.log(jindol.name)
console.log(jindol.barkSound)
jindol.bark()