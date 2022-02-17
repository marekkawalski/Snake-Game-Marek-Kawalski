<h1>Snake game</h1>
<p>Windows desktop 2D game. A combination of classic snake with couple of whimsical features.
</p>
<h2>Table of contents</h2>
<ul>
  <li>
    <a href="#generalInfo">General info</a>
  </li>
   <li>
    <a href="/README.md/#images">Images</a>
  </li>
  <li>
    <a href="/README.md/#howToPlay">How to play</a>
  </li>
  <li>
    <a href="/README.md/#technologies">Technologies used</a>
  </li>
   <li>
    <a href="/README.md/#environment">Programming environment</a>
  </li>
  <li>
    <a href="/README.md/#status">Project status</a>
  </li>
  </ul>
  <h2 id="generalInfo">General info</h2>
  <p>The goal of this application was to implement an alghoritm, which changes image contrast, in both c# and asm and compares their execution times.
So as to examine alghoritms execution times a comparison was made between images of diffrent quality. Each alghoritm (asm, c#, optimized c#) 
  performed image contrast processing on the same photos using the same contrast factor value. Immediately, it turned out that the fastest alghoritm was
  the one written in assembly. Alghoritm implemented in c# with Microsoft optimization turned on was almost two times slower. Shockingly, when optimization 
  was turned off, it took almost 10 times more time for c# alghoritm to perform the same image processing compared to asm.
  Detailed results of the comparison are below in images section.
</p>
    <h2 id="images">Images</h2>
    <img src="https://user-images.githubusercontent.com/56251920/154549353-0a9e57fb-6c31-4071-83a2-a4b4f88c11cb.png"></img>
   <h2 id="howToPlay">How to use</h2>
  <ol>
  <li>
   Start the program.
  </li>
   <li>
 Go through intro section
  </li>
  <li>
  Choose play
  </li>
  <li>
    Control snake:
    <ul>
      <li>Use <strong>W+S+D+A</strong> or <strong>arrows</strong> to move snake.</li>
      <li>Use <strong>space</strong> for shooting.</li>
      <li>Use <strong>shift</strong> for acceleration.</li>
      <li>Use <strong>p</strong> if you want to pause the game.</li>
    </ul>
  </li>
  </ul>
  <h2 id="technologies">Technologies used</h2> 
 <ul>
  <li>
   c++
  </li>
  <li>
    sfml
  </li>
  </ul>
   <h2 id="environment">Programming environment</h2> 
    <ul>
  <li>
   Visual studio
  </li>
  </ul>
    <h2 id="status">Project status</h2> 
    <p>Finished</p>
  
  
  
