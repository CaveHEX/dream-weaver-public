# Dream Weaver (Public)

## Premise
Dream Weaver aims to mix different renders and images to create a unique animated composition.

This is meant to be used to render a lot of compositions/animations, not to be a real-time engine. While we can preview the results in real-time, the renders will take longer. Everything is meant to run at 24 frames per second, there is no delta time, so two runs on the same seed will give two strictly identical results.

![img000](/out/screenshots/weaved_13685.png)
![img001](/out/screenshots/weaved_13937.png)
![img002](/out/screenshots/weaved_12699.png)

## Input Data (Images)
### Backgrounds
In /bin/data/backgrounds, drag the images you want to use in the png format. Dream Weaver will automatically find and use them at runtime, no need to tweak the code.
### Entities
In /bin/data/entities, drag images the you want to have as entities in the compositions.
### Simple Entities
png files at the root of the entities folder will be considered simple entities (No animation).
### Animated Entities
Create a directory, and put your image sequence inside to create an animated entity. The frames should be in the png format, and the animation speed is always considered to be 24 FPS in the current version.

## Controls
R : Replace the current scene with a new one
S : Saves a screenshot to /out/screenshots/
M : Start / Stop the recording in /out/movie/

## Scene
A scene is composed of a background, and a collection of entities. You can control the number of entity and additional behaviors in ```scene_t```.

## Resources (flyweight design pattern)
```ressources_t``` is in charge of gathering all the assets provided in the input folders. It acts as an interface to obtain references to the assets, that way we make sure that every image is only loaded once in memory.
The assets aren't all loaded at launch, only gathered in a collection of ```ressource_t```. It is only when we ask to use an asset for the first that that the associated images will be loaded into the memory.
This creates the artefact that the program freezes in-between each frame - But that is fine as this is intended to batch a lot of renders, and not to act as a real-time engine.

## How Dream-Weaver came to be
Dream Weaver is a sketch - a test run of a larger solution developped on another plateform. It regroups a small subset of the desired features we had in mind. It was used to get a feel of the workflow and pipeline associated with the goal we had in mind.

