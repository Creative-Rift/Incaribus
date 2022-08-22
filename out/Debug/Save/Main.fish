name: Main
entities:
  - name: Background
    active: true
    transform:
      entity_name: Background
      position:
        - 0
        - 0
        - 0
      scale:
        - 1
        - 1
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: MainCamera
    active: true
    transform:
      entity_name: MainCamera
      position:
        - 0
        - 0
        - 0
      scale:
        - 1
        - 1
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: Frog
    active: true
    transform:
      entity_name: Frog
      position:
        - 1000
        - 735
        - 0
      scale:
        - 2.5
        - 2.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: Opossum
    active: true
    transform:
      entity_name: Opossum
      position:
        - 1800
        - 250
        - 0
      scale:
        - 2.5
        - 2.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: Gem
    active: true
    transform:
      entity_name: Gem
      position:
        - 1300
        - 760
        - 0
      scale:
        - 2.5
        - 2.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: MenuMap
    active: true
    transform:
      entity_name: MenuMap
      position:
        - 0
        - 0
        - 0
      scale:
        - 2.5
        - 2.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: Player
    active: true
    transform:
      entity_name: Player
      position:
        - 210
        - 225
        - 0
      scale:
        - 3
        - 3
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: House
    active: true
    transform:
      entity_name: House
      position:
        - 500
        - 532
        - 0
      scale:
        - 2.5
        - 2.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: Title
    active: true
    transform:
      entity_name: Title
      position:
        - 0
        - 0
        - 0
      scale:
        - 1
        - 1
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: Subtitle
    active: true
    transform:
      entity_name: Subtitle
      position:
        - 0
        - 0
        - 0
      scale:
        - 1
        - 1
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
  - name: LastBG1
    active: true
    transform:
      entity_name: LastBG1
      position:
        - 0
        - 0
        - 0
      scale:
        - 5.5
        - 5.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
    parent: Background
  - name: LastBG2
    active: true
    transform:
      entity_name: LastBG2
      position:
        - 2112
        - 0
        - 0
      scale:
        - 5.5
        - 5.5
        - 1
      angle: 0
      rotation_axis:
        - 0
        - 1
        - 0
    parent: Background
manager:
  - name: SpriteManager
    valid: true
    active: true
    components:
      - entity_name: Gem
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 15
          - 13
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: Gem
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: MenuMap
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 768
          - 768
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: MapMenu
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: LastBG1
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 384
          - 240
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: Background1
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: Player
        invertX: true
        invertY: false
        rect:
          - 0
          - 0
          - 33
          - 32
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: Idle
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: LastBG2
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 384
          - 240
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: Background1
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: House
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 87
          - 108
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: House
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: Opossum
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 36
          - 28
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: Opossum
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
      - entity_name: Frog
        invertX: false
        invertY: false
        rect:
          - 0
          - 0
          - 35
          - 32
        color:
          r: 0
          g: 0
          b: 0
          a: 255
        material:
          textureName: Frog
          shader:
            fragment: resources/shaders/fragment_shader.glsl
            vertex: resources/shaders/vertex_shader.glsl
    layer:
      - name: Player
        index: 3
      - name: Opossum
        index: 0
      - name: Gem
        index: 2
      - name: Frog
        index: 2
      - name: House
        index: 1
      - name: LastBG2
        index: 0
      - name: LastBG1
        index: 0
      - name: MenuMap
        index: 0
  - name: AnimatorManager
    valid: true
    active: true
    components:
      - entity_name: Opossum
        rect:
          - 36
          - 28
        displayRect:
          - 0
          - 0
          - 36
          - 28
        endFrame: 7
        loopDelay: 0
        loop: true
        playOnStart: true
        fps: 0.142857149
        type: 0
      - entity_name: Frog
        rect:
          - 35
          - 32
        displayRect:
          - 0
          - 0
          - 35
          - 32
        endFrame: 5
        loopDelay: 5
        loop: true
        playOnStart: true
        fps: 0.166666672
        type: 0
      - entity_name: Gem
        rect:
          - 15
          - 13
        displayRect:
          - 0
          - 0
          - 15
          - 13
        endFrame: 6
        loopDelay: 0
        loop: true
        playOnStart: true
        fps: 0.125
        type: 0
      - entity_name: Player
        rect:
          - 33
          - 32
        displayRect:
          - 64
          - 0
          - 33
          - 32
        endFrame: 3
        loopDelay: 0
        loop: true
        playOnStart: true
        fps: 0.125
        type: 1
    layer:
      - name: Player
        index: 0
      - name: Opossum
        index: 0
      - name: Gem
        index: 0
      - name: Frog
        index: 0
  - name: AudioManager
    valid: true
    active: true
    components:
      - entity_name: MainCamera
        audioFile: Menu
        volume: 0.0
        pitch: 1
        playOnStart: true
    layer:
      - name: MainCamera
        index: 0
  - name: ScriptManager
    valid: false
  - name: BoxColliderManager
    valid: false
  - name: TextManager
    valid: true
    active: true
    components:
      - entity_name: Subtitle
        text: Press SPACE to start the game
        shader:
          fragment: resources/shaders/fragment_font.glsl
          vertex: resources/shaders/vertex_font.glsl
        color:
          r: 0.411764711
          g: 0.650980413
          b: 0.121568628
          a: 255
        posx: 300
        posy: 150
        scale: 1
        font: DefaultFont
      - entity_name: Title
        text: Incaribus
        shader:
          fragment: resources/shaders/fragment_font.glsl
          vertex: resources/shaders/vertex_font.glsl
        color:
          r: 0.411764711
          g: 0.650980413
          b: 0.121568628
          a: 255
        posx: 800
        posy: 1000
        scale: 1
        font: DefaultFont
    layer:
      - name: Subtitle
        index: 0
      - name: Title
        index: 0
  - name: RigidBody2DManager
    valid: false
  - name: CameraManager
    valid: true
    active: true
    components:
      - entity_name: MainCamera
        fov: 45
        size: 1
        clipNear: -1
        clipFar: 1000
        type: 1
    layer:
      - name: MainCamera
        index: 0