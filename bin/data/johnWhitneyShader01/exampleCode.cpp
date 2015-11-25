void main()
{
    vec2 uv = gl_FragCoord.xy / resolution.xy - vec2(0.5, 0.5);
    vec3 color = vec3(0.);
    
    float redVal   = [[time]] * (uv.x * HORIZ_SCALE + RED_SCALE);
    float redY     = sin(redVal)   * [[vertScale]];
    color.r        = drawLine(uv, redY);
    
    float greenVal = [[time]] * (uv.x * HORIZ_SCALE + GREEN_SCALE);
    float greenY   = sin(greenVal) * [[vertScale]];
    color.g        = drawLine(uv, greenY);
    
    float blueVal  = [[time]] * (uv.x * HORIZ_SCALE + BLUE_SCALE);
    float blueY    = sin(blueVal)  * [[vertScale]];
    color.b        = drawLine(uv, blueY);
    
    gl_FragColor = vec4(color, 1.0);
}